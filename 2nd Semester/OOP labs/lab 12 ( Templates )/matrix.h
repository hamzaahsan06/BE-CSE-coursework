// -- Q3 --
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

template <class T>
class Matrix
{
private:
    // holds 2x2 matrix of any data type
    T r1c1;
    T r1c2;
    T r2c1;
    T r2c2;

public:
    Matrix(T r1c1, T r1c2, T r2c1, T r2c2) // parametrized constructor
    {
        this->r1c1 = r1c1;
        this->r1c2 = r1c2;
        this->r2c1 = r2c1;
        this->r2c2 = r2c2;
    }

    void Determinant()
    {
        T det = (r1c1 * r2c2) - (r1c2 * r2c1); // calculates determinant

        cout << "Determinant: " << det << endl;
    }

    void Display() const
    {
        cout << "[" << r1c1 << "\t" << r1c2 << "]" << endl;
        cout << "[" << r2c1 << "\t" << r2c2 << "]" << endl;
    }

    Matrix operator+(const Matrix &other)
    {
        return Matrix(
            r1c1 + other.r1c1,
            r1c2 + other.r1c2,
            r2c1 + other.r2c1,
            r2c2 + other.r2c2);
    }
    Matrix operator-(const Matrix &other)
    {
        return Matrix(
            r1c1 - other.r1c1,
            r1c2 - other.r1c2,
            r2c1 - other.r2c1,
            r2c2 - other.r2c2);
    }
};

#endif // MATRIX_H