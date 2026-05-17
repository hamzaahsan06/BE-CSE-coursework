#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Complex_No
{
private:
    float real;
    float img;

public:
    // prototypes for constructors
    Complex_No(float, float);    // for parameterized constructor
    Complex_No();                // for default constructor
    Complex_No(Complex_No &obj); // for copy constructor

    // prototypes for Methods
    void Display(void);
    float Magnitude(void);
    Complex_No Add(Complex_No &obj);
};
// -------- Definition of constructors --------
// For parameterized
Complex_No::Complex_No(float r, float i)
{
    real = r;
    img = i;
}
// for default
Complex_No::Complex_No()
{
    real = 0;
    img = 0;
}
// for copy
Complex_No::Complex_No(Complex_No &obj)
{
    real = obj.real;
    img = obj.img;
}
// -------- Definition of methods --------
void Complex_No ::Display()
{
    cout << "Real Number: " << real << endl;
    cout << "Imaginary number: " << img << endl;
    cout << "Complex number: " << real << " + " << img << "i" << endl;
}
float Complex_No ::Magnitude()
{
    float mag;
    mag = sqrt((real * real) + (img * img));
    return mag;
}
Complex_No Complex_No::Add(Complex_No &obj)
{
    Complex_No temp;
    temp.real = real + obj.real; // adds real number of self object with real number of another object
    temp.img = img + obj.img;
    return temp; // returning result( temp object)
}
int main()
{
    Complex_No num1;       // created with default constructor
    Complex_No num2(4, 5); // created with paramterized constructor
    Complex_No num3(num2); // created with copy constructor
    Complex_No num4;

    cout << "Displaying 1st complex number" << endl;
    num1.Display();
    cout << "\nDisplaying 2nd complex number" << endl;
    num2.Display();
    cout << "\nDisplaying 3rd complex number, which is created by copying 2nd number" << endl;
    num3.Display();
    cout << "\nDisplaying magnitude of 2nd complex number" << endl;
    float mag = num2.Magnitude();
    cout << "Magnitude: " << mag << endl;
    cout << "\nAdding 2nd and 3rd complex number." << endl;
    num4 = num3.Add(num2);
    cout << "\nDisplaying 4th complex number, result of addition." << endl;
    num4.Display();
}

/*
-------- Output ----------
Displaying 1st complex number
Real Number: 0
Imaginary number: 0
Complex number: 0 + 0i

Displaying 2nd complex number
Real Number: 4
Imaginary number: 5
Complex number: 4 + 5i

Displaying 3rd complex number, which is created by copying 2nd number
Real Number: 4
Imaginary number: 5
Complex number: 4 + 5i

Displaying magnitude of 2nd complex number
Magnitude: 6.40312

Adding 2nd and 3rd complex number.

Displaying 4th complex number, result of addition.
Real Number: 8
Imaginary number: 10
Complex number: 8 + 10i*/
