#include <iostream>
using namespace std;

int **readMatrix(int rows, int cols)
{
    int **A = new int *[rows];

    cout << "Enter elements of matrix (" << rows << "x" << cols << "):\n";

    for (int row = 0; row < rows; row++)
    {
        A[row] = new int[cols];
        for (int col = 0; col < cols; col++)
        {
            cout << "Write element for row " << row + 1 << " and coloumn " << col + 1 << " > ";
            cin >> A[row][col];
        }
    }

    return A;
}
void printMatrix(int **A, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << A[i][col] << "  ";
        }
        cout << endl;
    }
}
void delMat(int **A, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] A[i]; // Deletes all elements in the ith row
    }
    delete[] A; // Deletes the array of row pointers
}

int **matMul(int rA, int cA, int rB, int cB)
{
    if (cA != rB)
    {
        return NULL;
    }

    int **A = readMatrix(rA, cA);
    int **B = readMatrix(rB, cB);

    int **C = new int *[rA]; // Creates an array of rA row pointers

    for (int row = 0; row < rA; row++)
    {
        C[row] = new int[cB];              // Dynamically allocates memory for coloumn ( size of each row )
        for (int col = 0; col < cB; col++) // Moves through columns while keeping the same row
        {
            C[row][col] = 0;
            for (int k = 0; k < cA; k++)
            {
                C[row][col] += A[row][k] * B[k][col];
            }
        }
    }

    delMat(A, rA);
    delMat(B, rB);

    return C;
}

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

    int **C = matMul(rA, cA, rB, cB);
    if (C == NULL)
    {
        cout << "Multiplication can not possible" << endl;
        return 0;
    }

    cout << "Product matrix C = A x B:\n";
    printMatrix(C, rA, cB);

    delMat(C, rA);

    return 0;
}
/*
Output
Enter number of rows for matrix A:
> 2
Enter number of coloumns for matrix A:
> 3
Enter number of rows for matrix B:
> 3
Enter number of coloumns for matrix B:
> 2
Enter elements of matrix (2x3):
Write element for row 1 and coloumn 1 > 1
Write element for row 1 and coloumn 2 > 2
Write element for row 1 and coloumn 3 > 3
Write element for row 2 and coloumn 1 > 4
Write element for row 2 and coloumn 2 > 5
Write element for row 2 and coloumn 3 > 6
Enter elements of matrix (3x2):
Write element for row 1 and coloumn 1 > 7
Write element for row 1 and coloumn 2 > 8
Write element for row 2 and coloumn 1 > 9
Write element for row 2 and coloumn 2 > 10
Write element for row 3 and coloumn 1 > 11
Write element for row 3 and coloumn 2 > 12
Product matrix C = A x B:
58  64  
139  154 
*/