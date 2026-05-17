#include <iostream>
#include <cmath>
using namespace std;

class Vector
{
private:
    int x, y;

public:
    Vector(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    int &operator[](int index)
    {
        if (index == 0)
            return x;
        if (index == 1)
            return y;
        else
        {
            cout << "Invalid index" << endl;
            exit(1); // throws error
        }
    }

    friend ostream &operator<<(ostream &out, Vector &v);
    friend istream &operator>>(istream &in, Vector &v);
};

ostream &operator<<(ostream &out, Vector &v)
{
    out << "( " << v.x << ", " << v.y << " )";
    return out;
}

istream &operator>>(istream &in, Vector &v)
{
    cout << "Enter x-coordinate:\n> ";
    in >> v.x;

    cout << "Enter y-coordinate:\n> ";
    in >> v.y;

    return in;
}

int main()
{
    Vector v;
    cout << "Input values of a vector: " << endl;
    cin >> v;

    cout << "Index[0] : " << v[0] << endl;
    cout << "Index[1] : " << v[1] << endl;
    cout << "Vector : " << v;

    // Testing modification
    v[0] = 10;
    v[1] = 20;

    cout << "\nAfter modification: " << v << endl;
}

/*
Output


Input values of a vector: 
Enter x-coordinate:
> 7
Enter y-coordinate:
> 7
Index[0] : 7
Index[1] : 7
Vector : ( 7, 7 )
After modification: ( 10, 20 )

*/
