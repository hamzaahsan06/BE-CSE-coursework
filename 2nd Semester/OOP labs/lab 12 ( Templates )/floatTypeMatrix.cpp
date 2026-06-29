// -- Q4 --
#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    Matrix<float> A(1.5, 2.0, 3.0, 4.5); // A is instance matrix and attributes of A is of type float.
    Matrix<float> B(2.5, 1.0, 0.5, 3.5);

    cout << "Matrix A:\n";
    A.Display();
    cout << "Matrix B:\n";
    B.Display();

    Matrix<float> sum = A + B;
    Matrix<float> diff = A - B;

    cout << "\nA + B:\n";
    sum.Display();
    cout << "\nA - B:\n";
    diff.Display();

    cout << "\nDeterminant of A:\n";
    A.Determinant();
    cout << "Determinant of B:\n";
    B.Determinant();

    return 0;
}