// ---------- exercise 1 ----------
#include <iostream>
using namespace std;
class Complex_num
{
    // private by default
    int real;
    int img;

public:
    void input_real()
    {
        cout << "Enter real part: ";
        cin >> real;
    }
    void input_img()
    {
        cout << "Enter imaginary part: ";
        cin >> img;
    }
    // defining inline function
    void display()
    {
        cout << "\nComplex number is: " << real << " + " << img << "i";
    }
};
/* defining outline function
void Complex_num::display()
{
    cout << "\nComplex number is: " << real << " + " << img << "i";
} */
int main()
{
    Complex_num cl; // Object creation
    // calling object's functions
    cl.input_real();
    cl.input_img();
    cl.display();
}