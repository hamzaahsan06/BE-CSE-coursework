// -- Q5 --
#include <iostream>
#include "matrix.h"
#include "complexNumber.h"
using namespace std;

int main()
{
    Matrix<complexNumber> matA(
        complexNumber(1, 2), complexNumber(3, 4),
        complexNumber(5, 6), complexNumber(7, 8));

    Matrix<complexNumber> matB(
        complexNumber(2, 1), complexNumber(1, 1),
        complexNumber(0, 1), complexNumber(3, 2));

    cout << "Matrix A:\n";
    matA.Display();
    cout << "Matrix B:\n";
    matB.Display();

    Matrix<complexNumber> sum = matA + matB;
    Matrix<complexNumber> diff = matA - matB;

    cout << "\nA + B:\n";
    sum.Display();
    cout << "\nA - B:\n";
    diff.Display();

    return 0;
}