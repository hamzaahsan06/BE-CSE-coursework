#include <iostream>
#include <string>
using namespace std;

class Counter
{
private:
    int value;

public:
    Counter() { value = 0; } // Default constructor
    // methods
    void Increment(void) { value += 1; }
    void Decrement(void) { value -= 1; }
    void Display(void) { cout << "Value: " << value << endl; }
};

int main()
{
    Counter obj;
    cout << "Displaying the value after constructing" << endl;
    obj.Display();
    cout << "\nDisplaying the value after increment" << endl;
    obj.Increment();
    obj.Display();
    cout << "\nDisplaying the value after decrement" << endl;
    obj.Decrement();
    obj.Display();
    return 0;
}
/*
Displaying the value after constructing
Value: 0

Displaying the value after increment
Value: 1

Displaying the value after decrement
Value: 0
*/