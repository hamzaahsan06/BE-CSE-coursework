#include <iostream>
#include <cctype> // for isdigit
#include <cstring>
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
            return;
        }

        data[++tos] = element;
    }
    T pop()
    {
        T element;
        if (isEmpty())
        {
            return T();
        }
        element = data[tos];
        tos--;
        return element;
    }
    T peek()
    {
        if (isEmpty())
        {
            return T();
        }
        return data[tos];
    }
};

bool palindrome(char *str)
{
    int length = strlen(str);
    if (length == 0) return true; // Empty string is a palindrome

    Stack<char> st(length);

    // Start at the last valid character (length - 1)
    int index = 0;
    while (index < length)
    {
        st.push(str[index]); // The top element of stack is last element of str
        index++;
    }

    index = 0;
    while (index < length)
    {
        if (st.pop() != str[index++])
        {
            return false;
        }
    }

    return true;
}