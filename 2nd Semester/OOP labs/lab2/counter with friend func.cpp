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
    // prototype for adding friend function in this class
    friend void Reset(Counter &);
};
// Defining Reset function for Counter class
void Reset(Counter &obj)
{
    obj.value = 0;
}

int main()
{
    Counter obj;
    cout << "Displaying the value after constructing" << endl;
    obj.Display();
    cout << "\nDisplaying the value after increment" << endl;
    obj.Increment();
    obj.Display();
    cout << "\nDisplaying the value after calling reset function(friend function)" << endl;
    Reset(obj);
    obj.Display();
    return 0;
}
/*
Displaying the value after constructing
Value: 0

Displaying the value after increment
Value: 1

Displaying the value after calling reset function(friend function)
Value: 0
*/