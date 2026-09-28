#include <iostream>
using namespace std;

int **readMatrix(int n)
{
    int **A = new int *[n];

    for (int row = 0; row < n; row++)
    {
        A[row] = new int[n];
        for (int col = 0; col < n; col++)
        {
            cout << "Write element for row " << row + 1 << " and coloumn " << col + 1 << " > ";
            cin >> A[row][col];
        }
    }

    return A;
}
void printMatrix(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << A[i][col] << "  ";
        }
        cout << endl;
    }
}
void delMat(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] A[i]; // Deletes all elements in the ith row
    }
    delete[] A; // Deletes the array of row pointers
}

int *storeTriangular(int **A, int size)
{
    int n = size * (size + 1) / 2;
    int *U = new int[n];
    int i = 0;                           // Index of uni-directional array
    for (int row = 0; row < size; row++) // Access rows of sparse matrix
    {
        for (int element = 0; element <= row; element++) // Access row's elements of sparse matrix
        {
            U[i++] = A[row][element];
        }
    }
    return U;
}

int **RetrieveTriangular(int U[], int size)
{
    int **A = new int *[size];
    for (int row = 0; row < size; row++)
    {
        A[row] = new int[size];
        for (int col = 0; col < size; col++)
        {
            A[row][col] = 0; // Initialize complete row with 0
            if (col > row)
            {
                A[row][col] = 0;
            }
            else
            {
                A[row][col] = U[(row * (row + 1) / 2) + col];
            }
        }
    }
    return A;
}

int main()
{
    int size;
    cout << "Enter size(n) for nxn lower triangular matrix:\n> ";
    cin >> size;

    int Usize = size * (size + 1) / 2;

    int **A = readMatrix(size);
    cout << "\nOriginal matrix:\n";
    printMatrix(A, size);

    int *U = storeTriangular(A, size);

    cout << "\nU = [";
    for (int i = 0; i < Usize; i++)
    {
        cout << U[i];
        if (i < Usize - 1)
            cout << ", ";
    }
    cout << "]\n";

    int **B = RetrieveTriangular(U, size);
    cout << "\nRetrieved matrix:\n";
    printMatrix(B, size);

    delMat(A, size);
    delMat(B, size);
    delete[] U;

    return 0;
}

/* Output

Original matrix:
4  0  0  0  
3  -5  0  0  
1  6  2  0  
8  0  5  9  

U = [4, 3, -5, 1, 6, 2, 8, 0, 5, 9]

Retrieved matrix:
4  0  0  0  
3  -5  0  0  
1  6  2  0  
8  0  5  9 

*/