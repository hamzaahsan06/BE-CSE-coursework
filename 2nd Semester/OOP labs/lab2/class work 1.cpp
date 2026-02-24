#include <iostream>
using namespace std;

class complex_num
{
    int real;
    int imaginary;

public:
    // inline user input constructor
    // complex_num()
    // {
    //     cout << "Enter real part: ";
    //     cin >> real;
    //     cout << "Enter imaginary part: ";
    //     cin >> imaginary;
    // }
    
    complex_num();                              // prototype for default value.
    complex_num(int r, int i);                  // prototype for parameterized value.
    complex_num(complex_num &c);                // prototype for copy constructor.
    // inline destructor
    ~complex_num()
    {
        cout << "DESTROYING THE OBJECT" << endl;
    }
    
    void display();
};

// copy constructor
complex_num ::complex_num(complex_num &c)      // copy constructor recieves class name as an argument and &(*) for refrance of class object.
{
    real = c.real;
    imaginary = c.imaginary;
}

// outline parameterized value constructor.
complex_num ::complex_num(int r, int i)
{
    real = r;
    imaginary = i;
}

// outline default value constructor.
complex_num ::complex_num()
{
    real = 0;
    imaginary = 0;
}

void complex_num ::display()
{
    cout << "\nComplex number: " << real << " + " << imaginary << "i" << endl;
}

int main()
{
    complex_num c2(6, 9);
    complex_num c3(c2);    // it recieves refrence of c2 as an argument
    c2.display();
    c3.display();
}