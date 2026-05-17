#include <iostream>
#include <cmath>
using namespace std;

class complexNumber
{
private:
    int real, imaginary;

public:
    complexNumber(int r = 0, int img = 0)
    {
        real = r;
        imaginary = img;
    }

    float getMagnitude() const
    {
        float mag = pow((pow(real, 2) + pow(imaginary, 2)), 0.5);
        return mag;
    }

    complexNumber operator+(const complexNumber &obj)
    {
        complexNumber temp;
        temp.real = real + obj.real;
        temp.imaginary = imaginary + obj.imaginary;
        return temp;
    }

    complexNumber operator-(const complexNumber &obj)
    {
        complexNumber temp;
        temp.real = real - obj.real;
        temp.imaginary = imaginary - obj.imaginary;
        return temp;
    }

    complexNumber operator*(const complexNumber &obj)
    {
        complexNumber temp;
        // a*b = (ac-bd), (ad+bc)
        temp.real = (real * obj.real) - (imaginary * obj.imaginary);
        temp.imaginary = (real * obj.imaginary) + (imaginary * obj.real);
        return temp;
    }

    complexNumber operator/(const complexNumber &obj)
    {
        complexNumber temp;
        // a*b = (ac-bd), (ad+bc)
        temp.real = ((real * obj.real) + (imaginary * obj.imaginary)) / (pow(obj.real, 2) + pow(obj.imaginary, 2));
        temp.imaginary = ((imaginary * obj.real) - (real * obj.imaginary)) / (pow(obj.real, 2) + pow(obj.imaginary, 2));
        return temp;
    }

    complexNumber operator--()
    {
        --real;
        --imaginary;
        return *this;
    }

    complexNumber operator--(int a)
    {
        complexNumber temp = *this;
        --real;
        --imaginary;
        return temp;
    }

    complexNumber operator++()
    {
        ++real;
        ++imaginary;
        return *this;
    }

    complexNumber operator++(int a)
    {
        complexNumber temp = *this;
        ++real;
        ++imaginary;
        return temp;
    }

    bool operator>(const complexNumber &obj)
    {
        return getMagnitude() > obj.getMagnitude();
    }

    bool operator<(const complexNumber &obj)
    {
        return getMagnitude() < obj.getMagnitude();
    }

    bool operator==(const complexNumber &obj)
    {
        return getMagnitude() == obj.getMagnitude();
    }

    void display()
    {
        cout << "Complex Number ( " << real << " , " << imaginary << " )" << endl;
        cout << "Magnitude : " << this->getMagnitude();
    }
};

int main()
{
    complexNumber c1(3, 4), c2(1, 2);

    cout << "=== c1 ===" << endl;
    c1.display();

    cout << "\n\n=== c2 ===" << endl;
    c2.display();

    // Addition
    cout << "\n\n--- c1 + c2 ---" << endl;
    complexNumber c3 = c1 + c2;
    c3.display();

    // Subtraction
    cout << "\n\n--- c1 - c2 ---" << endl;
    complexNumber c4 = c1 - c2;
    c4.display();

    // Multiplication
    cout << "\n\n--- c1 * c2 ---" << endl;
    complexNumber c5 = c1 * c2;
    c5.display();

    // Division
    cout << "\n\n--- c1 / c2 ---" << endl;
    complexNumber c6 = c1 / c2;
    c6.display();

    // Prefix decrement
    cout << "\n\n--- Prefix: --c1 ---" << endl;
    complexNumber preDec = --c1;
    cout << "Returned (new value): \n";
    preDec.display();
    cout << "\nCurrent c1: ";
    c1.display();

    // Postfix decrement
    cout << "\n\n--- Postfix: c1-- ---" << endl;
    complexNumber postDec = c1--;
    cout << "Returned (old value): \n";
    postDec.display();
    cout << "\nCurrent c1: ";
    c1.display();

    // Prefix increment
    cout << "\n\n--- Prefix: ++c1 ---" << endl;
    complexNumber preInc = ++c1;
    cout << "Returned (new value): \n";
    preInc.display();
    cout << "\nCurrent c1: ";
    c1.display();

    // Postfix increment
    cout << "\n\n--- Postfix: c1++ ---" << endl;
    complexNumber postInc = c1++;
    cout << "Returned (old value): \n";
    postInc.display();
    cout << "\nCurrent c1: ";
    c1.display();

    // Comparison
    cout << "\n\n--- Comparisons ---" << endl;
    if (c1 > c2)
        cout << "c1 is greater than c2" << endl;
    else if (c1 < c2)
        cout << "c1 is less than c2" << endl;
    else if (c1 == c2)
        cout << "c1 and c2 are equal" << endl;

    return 0;
}

/* Output

=== c1 ===
Complex Number ( 3 , 4 )
Magnitude : 5

=== c2 ===
Complex Number ( 1 , 2 )
Magnitude : 2.23607

--- c1 + c2 ---
Complex Number ( 4 , 6 )
Magnitude : 7.2111

--- c1 - c2 ---
Complex Number ( 2 , 2 )
Magnitude : 2.82843

--- c1 * c2 ---
Complex Number ( -5 , 10 )
Magnitude : 11.1803

--- c1 / c2 ---
Complex Number ( 2 , 0 )
Magnitude : 2

--- Prefix: --c1 ---
Returned (new value):
Complex Number ( 2 , 3 )
Magnitude : 3.60555
Current c1: Complex Number ( 2 , 3 )
Magnitude : 3.60555

--- Postfix: c1-- ---
Returned (old value):
Complex Number ( 2 , 3 )
Magnitude : 3.60555
Current c1: Complex Number ( 1 , 2 )
Magnitude : 2.23607

--- Prefix: ++c1 ---
Returned (new value):
Complex Number ( 2 , 3 )
Magnitude : 3.60555
Current c1: Complex Number ( 2 , 3 )
Magnitude : 3.60555

--- Postfix: c1++ ---
Returned (old value):
Complex Number ( 2 , 3 )
Magnitude : 3.60555
Current c1: Complex Number ( 3 , 4 )
Magnitude : 5

--- Comparisons ---
c1 is greater than c2

*/
