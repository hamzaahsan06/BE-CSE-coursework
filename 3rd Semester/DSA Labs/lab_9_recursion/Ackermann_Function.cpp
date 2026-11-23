#include <iostream>
using namespace std;

unsigned long long ackermann(unsigned long long x, unsigned long long y)
{
    if (x == 0)
    {
        return y + 1;
    }
    else if (x > 0 && y == 0)
    {
        return ackermann(x - 1, 1);
    }
    else
    { // x > 0 && y > 0
        return ackermann(x - 1, ackermann(x, y - 1));
    }
}

int main()
{
    cout << "Ackermann Function Calculations:" << endl;
    cout << "A(0, 0) = " << ackermann(0, 0) << endl;
    cout << "A(1, 2) = " << ackermann(1, 2) << endl;
    cout << "A(2, 2) = " << ackermann(2, 2) << endl;
    cout << "A(3, 2) = " << ackermann(3, 2) << endl;
    cout << "A(3, 3) = " << ackermann(3, 3) << endl;

    return 0;
}