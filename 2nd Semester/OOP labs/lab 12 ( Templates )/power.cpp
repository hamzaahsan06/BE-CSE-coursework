// -- Q2 --
#include <iostream>
using namespace std;

template <typename T>
T Power(T x, int y)
{
    T result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}

int main()
{
    cout << "Power(2, 5) = " << Power(2, 5) << endl;     // int
    cout << "Power(2.5, 3) = " << Power(2.5, 3) << endl; // double
    return 0;
}

/*
Output

Power(2, 5) = 32
Power(2.5, 3) = 15.625

*/
