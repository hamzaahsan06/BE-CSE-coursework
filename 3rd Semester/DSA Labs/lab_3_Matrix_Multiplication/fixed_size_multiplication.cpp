#include <iostream>
using namespace std;

int **matMul(int **A, int **B, int n)
{
    int **C = new int *[n]; // Creates an array of n row pointers

    for (int row = 0; row < n; row++)
    {
        C[row] = new int[n];              // Dynamically allocates memory for coloumn ( size of each row )
        for (int col = 0; col < n; col++) // Moves through columns while keeping the same row
        {
            C[row][col] = 0;
            for (int k = 0; k < n; k++)
            {
                C[row][col] += A[row][k] * B[k][col];
            }
        }
    }
    return C;
}

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
int main()
{
    int n;
    cout << "Enter size n: ";
    cin >> n;

    cout << "Enter elements of matrix A (" << n << "x" << n << "):\n";
    int **A = readMatrix(n);

    cout << "Enter elements of matrix B (" << n << "x" << n << "):\n";
    int **B = readMatrix(n);

    int **C = matMul(A, B, n);

    cout << "Product matrix C = A x B:\n";
    printMatrix(C, n);

    delMat(A, n);
    delMat(B, n);
    delMat(C, n);

    return 0;
}
/* Output of product portion only

Product matrix C = A x B:
13  4  13  
28  10  34  
43  16  55 

*/