#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **data;

    // helper to allocate a rows x cols 2D array
    int **allocate(int r, int c)
    {
        int **arr = new int *[r];
        for (int i = 0; i < r; i++)
            arr[i] = new int[c];
        return arr;
    }

public:
    // Constructor: creates an empty matrix of given size
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data = allocate(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = 0;
    }

    // Copy constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
    {
        data = allocate(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
    }

    // Destructor: frees the dynamically allocated memory
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Read elements from user
    void readMatrix()
    {
        cout << "Enter elements of matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Element [" << i + 1 << "][" << j + 1 << "] > ";
                cin >> data[i][j];
            }
        }
    }

    // Print the matrix
    void print() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << "  ";
            cout << endl;
        }
    }

    // Overloaded * operator: performs matrix multiplication with size check
    Matrix operator*(const Matrix &other) const
    {
        if (this->cols != other.rows)
        {
            cout << "Error: dimension mismatch, cannot multiply ("
                 << this->rows << "x" << this->cols << ") with ("
                 << other.rows << "x" << other.cols << ")\n";
            exit(1);
        }

        Matrix result(this->rows, other.cols);

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < this->cols; k++)
                {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }
};

int main()
{
    int rA, cA, rB, cB;
    cout << "Enter number of rows for matrix A:\n> ";
    cin >> rA;
    cout << "Enter number of coloumns for matrix A:\n> ";
    cin >> cA;
    cout << "Enter number of rows for matrix B:\n> ";
    cin >> rB;
    cout << "Enter number of coloumns for matrix B:\n> ";
    cin >> cB;

    Matrix A(rA, cA);
    A.readMatrix();

    Matrix B(rB, cB);
    B.readMatrix();

    Matrix C = A * B;

    cout << "Product matrix C = A x B:\n";
    C.print();

    return 0;
}
/*
Output of product portion only
Product matrix C = A x B:
58  64  
139  154 
*/