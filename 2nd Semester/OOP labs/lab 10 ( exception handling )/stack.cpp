#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
private:
    int stack[10];
    int elementsCount;

public:
    Stack() { elementsCount = 0; };
    void Push(int x)
    {
        if (elementsCount >= 10)
        {
            throw overflow_error("Stack Overflow.");
        }

        stack[elementsCount] = x;
        elementsCount++;
        cout << x << " pushed into stack." << endl;
    }
    void Pop()
    {
        if (elementsCount == 0)
        {
            throw underflow_error("Stack underflow.");
        }

        elementsCount--;
        cout << "Element popped from stack." << endl;
    }

    void display() const
    {
        cout << "-- Stack Elements -- " << endl;
        for (int i = 0; i < elementsCount; i++)
        {
            cout << "Element " << i + 1 << ": " << stack[i] << endl;
        }
    }
};
int main()
{
    Stack stack;
    try
    {
        // stack.Pop(); // To check underflow error.
        for (int i = 10; i <= 21; i++) // causes overflow
            stack.Push(i);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    stack.display();
}

/*

Output
10 pushed into stack.
11 pushed into stack.
12 pushed into stack.
13 pushed into stack.
14 pushed into stack.
15 pushed into stack.
16 pushed into stack.
17 pushed into stack.
18 pushed into stack.
19 pushed into stack.
Stack Overflow.
-- Stack Elements --
Element 1: 10
Element 2: 11
Element 3: 12
Element 4: 13
Element 5: 14
Element 6: 15
Element 7: 16
Element 8: 17
Element 9: 18
Element 10: 19

*/
