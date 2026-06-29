// -- Q5 --
#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>
using namespace std;

class complexNumber
{
    int real;
    int imaginary;

public:
    complexNumber(int r = 0, int i = 0) : real(r), imaginary(i) {}
    void display()
    {
        cout << "\nComplex number is: " << real << " + " << imaginary << "i";
    }
    complexNumber operator+(const complexNumber &obj)
    {
        return complexNumber(real + obj.real, imaginary + obj.imaginary);
    }

    complexNumber operator-(const complexNumber &obj)
    {
        return complexNumber(real - obj.real, imaginary - obj.imaginary);
    }

    friend ostream &operator<<(ostream &os, const complexNumber &cn)
    {
        os << cn.real << (cn.imaginary >= 0 ? "+" : "") << cn.imaginary << "i";
        return os;
    }
};

#endif //COMPLEX_NUMBER_H