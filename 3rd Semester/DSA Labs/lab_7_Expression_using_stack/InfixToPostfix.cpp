#include <iostream>
#include <cctype> // for isdigit
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

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool checkPrecedence(char Qop, char TOS)
{
    return precedence(TOS) >= precedence(Qop);
}

char* infixToPostfix(char* Q)
{
    int length = len(Q);
    char* P = new char[length + 1];
    Stack<char> st(length + 1);
    int Qindex = 0;
    int Pindex = 0;

    st.push('(');
    Q[length] = ')';

    while (Q[Qindex] != '\0')
    {
        if (isdigit(Q[Qindex]))
        {
            P[Pindex++] = Q[Qindex];
        }
        else if (Q[Qindex] == '(')
        {
            st.push(Q[Qindex]);
        }
        else if (Q[Qindex] == '+' || Q[Qindex] == '-' || 
                 Q[Qindex] == '*' || Q[Qindex] == '/')
        {
            while (checkPrecedence(Q[Qindex], st.peek()))
            {
                P[Pindex++] = st.pop();
            }
            st.push(Q[Qindex]);
        }
        else if (Q[Qindex] == ')')
        {
            // Pop operators from stack until matching opening parenthesis is encountered
            while (st.peek() != '(')
            {
                P[Pindex++] = st.pop();
            }
            st.pop(); // Discard the opening parenthesis from the stack
        }
        Qindex++;
    }

    return P;
}

int main()
{
    char Q[] = "3+4*2/(1-5)";

    cout << "Result: " << infixToPostfix(Q) << endl;

    return 0;
}