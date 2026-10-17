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

int len(char *P)
{
    int length = 0;
    while (P[length] != '\0')
    {
        length++;
    }
    return length;
}

int postFixExpression(char *P)
{
    int length = len(P);
    Stack<int> st(length);

    int index = 0;

    while (P[index] != '\0')
    {
        if (isdigit(P[index]))
        {
            st.push(P[index] - '0');
        }

        else if (P[index] == '+' || P[index] == '-' ||
                 P[index] == '*' || P[index] == '/')
        {
            int operand2 = st.pop();
            int operand1 = st.pop();

            switch (P[index])
            {
            case '+':
                st.push(operand1 + operand2);
                break;

            case '-':
                st.push(operand1 - operand2);
                break;

            case '*':
                st.push(operand1 * operand2);
                break;

            case '/':
                if (operand2 == 0)
                    return 0; // handled or check division by zero
                st.push(operand1 / operand2);
                break;
            }
        }

        index++;
    }

    return st.pop();
}

int main()
{
    char P[] = "23*54/9";

    cout << "Result: " << postFixExpression(P) << endl;

    return 0;
}