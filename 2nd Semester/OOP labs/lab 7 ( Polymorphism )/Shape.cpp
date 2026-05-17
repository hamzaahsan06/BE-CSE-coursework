#include <iostream>
using namespace std;
class Shape
{
protected:
    double Area;

public:
    // Default constructor
    Shape() : Area(0) {}
    // pure virtual function
    virtual double Calculate_Area() = 0;
    // Method(s)
    virtual void Display()
    {
        cout << "Area : " << Area << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) { radius = r; }

    void Display() override
    {
        cout << "Radius of the circle is : " << radius << endl;
        cout << "Area of the circle is : " << Area << endl;
    }

    double Calculate_Area() override
    {
        Area = 3.142 * (radius * radius);
        return Area;
    }
};

class Rectangle : public Shape
{
private:
    double length, breadth;

public:
    Rectangle(double l, double b)
    {
        length = l;
        breadth = b;
    }

    void Display() override
    {
        cout << "Lenghth of the rectangle is : " << length << endl;
        cout << "Breadth of the rectangle is : " << breadth << endl;
        cout << "Area of the rectangle is : " << Area << endl;
    }

    double Calculate_Area() override
    {
        Area = length * breadth;
        return Area;
    }
};

int main()
{
    double radius, length, breadth;
    cout << "Enter radius of circle\n> ";
    cin >> radius;

    Circle c(radius);
    c.Calculate_Area();
    c.Display();

    cout << "Enter length of rectangle\n> ";
    cin >> length;
    cout << "Enter beadth of rectangle\n> ";
    cin >> breadth;
    Rectangle R(length, breadth);
    R.Calculate_Area();
    R.Display();

    return 0;
}
