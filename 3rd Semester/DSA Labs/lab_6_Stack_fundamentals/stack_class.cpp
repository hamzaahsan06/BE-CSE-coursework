#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *data;
    int tos;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        data = new T[capacity];
        tos = -1;
    }
    ~Stack()
    {
        delete[] data;
    }
    bool isFull() const
    {
        return tos == capacity - 1;
    }
    bool isEmpty() const
    {
        return tos == -1;
    }
    void push(T element)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << element << endl;
            return;
        }

        data[++tos] = element;
        cout << element << " pushed onto the stack." << endl;
    }
    T pop()
    {
        T element;
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return T();
        }
        element = data[tos];
        cout << data[tos] << " popped from the stack." << endl;
        tos--;
        return element;
    }
    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return T();
        }
        return data[tos];
    }
};
int main()
{
    cout << "=== Integer Stack ===" << endl;
    Stack<int> intStack(2);

    intStack.pop(); // Trigger Stack Underflow
    
    intStack.push(10);
    intStack.push(20);
    intStack.push(30); // Trigger Stack Overflow

    cout << "Current Top Element: " << intStack.peek() << endl;

    intStack.pop();

    cout << "Current Top Element: " << intStack.peek() << endl;
}