#include <iostream>
#include <cmath>
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

// Q3
int *storeTrdiagonal(int **A, int size)
{
    int n = 3 * size - 2;
    int *U = new int[n];
    int i = 0;                           // Index of uni-directional array
    for (int row = 0; row < size; row++) // Access rows of sparse matrix
    {
        for (int element = 0; element < size; element++) // Access row's elements of sparse matrix
        {
            if (abs(row - element) <= 1)
            {
                U[i++] = A[row][element];
            }
        }
    }
    return U;
}
// Q4
int **RetrieveTridiagonal(int U[], int size)
{
    int **A = new int *[size];
    for (int row = 0; row < size; row++)
    {
        A[row] = new int[size];
        for (int col = 0; col < size; col++)
        {
            A[row][col] = 0; // Initialize complete row with 0
            if (abs(row - col) <= 1)
            {
                A[row][col] = U[2 * row + col];
            }
            else
            {
                A[row][col] = 0;
            }
        }
    }
    return A;
}

int main()
{
    int size;
    cout << "Enter size(n) for nxn tridiagonal matrix:\n> ";
    cin >> size;

    int Usize = 3 * size - 2;

    int **A = readMatrix(size);
    cout << "\nOriginal matrix:\n";
    printMatrix(A, size);

    int *U = storeTrdiagonal(A, size);

    cout << "\nU = [";
    for (int i = 0; i < Usize; i++)
    {
        cout << U[i];
        if (i < Usize - 1)
            cout << ", ";
    }
    cout << "]\n";

    int **B = RetrieveTridiagonal(U, size);
    cout << "\nRetrieved matrix:\n";
    printMatrix(B, size);

    delMat(A, size);
    delMat(B, size);
    delete[] U;

    return 0;
}
/*
Output of matrix portion only

Original matrix:
4  1  0  0  0  
2  5  2  0  0  
0  3  6  1  0  
0  0  1  4  3  
0  0  0  2  7  

U = [4, 1, 2, 5, 2, 3, 6, 1, 1, 4, 3, 2, 7]

Retrieved matrix:
4  2  0  0  0  
1  5  3  0  0  
0  2  6  1  0  
0  0  1  4  2  
0  0  0  3  7  
*/