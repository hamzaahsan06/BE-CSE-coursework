// -- Q1 --
#include <iostream>
using namespace std;

template <class T> // template declaration
T max(T arr[], int size)
{
    T max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    int Iarr[5] = {1, 2, 3, 4, 5};
    int maxI = max(Iarr, 5);

    cout << "Maximum integer in an array: " << maxI << endl;

    float Farr[5] = {1.9, 2.3, 3.1, 4.5, 5.6};
    float maxF = max(Farr, 5);
    cout << "Maximum float in an array: " << maxF << endl;
}

/*
Output

Maximum integer in an array: 5
Maximum float in an array: 5.6


*/


