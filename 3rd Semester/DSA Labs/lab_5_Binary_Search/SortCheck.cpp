#include <iostream>
#include <algorithm>
using namespace std;

int *inputData(int &size)
{
    cout << "Enter Size of array: \n>";
    cin >> size;
    int *arr = new int[size];

    bool sorted = false;
    while (!sorted)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }

        sorted = is_sorted(arr, arr + size);
        if (!sorted)
            cout << "Array is not sorted. Please re-enter.\n";
    }

    return arr;
}

int *BinSearchInsert(int data[], int &size, int element)
{
    int beg = 0;
    int end = size - 1;
    int mid;

    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (data[mid] == element)
        {
            cout << "Element " << element << " found at index " << mid << ".\n";
            return data; // found, no insertion needed
        }
        else if (element < data[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }

    int *newData = new int[size + 1];

    for (int i = 0; i < beg; i++)
        newData[i] = data[i];

    newData[beg] = element;

    for (int i = beg; i < size; i++)
        newData[i + 1] = data[i];

    delete[] data;
    size++;

    cout << "Element " << element << " not found. Inserted at index " << beg << ".\n";
    return newData;
}

void printArray(int *arr, int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size;
    int *arr = inputData(size);

    cout << "\nSorted array accepted!\n";
    printArray(arr, size);

    int element;
    cout << "\nEnter element to search: ";
    cin >> element;

    arr = BinSearchInsert(arr, size, element);

    cout << "\nFinal ";
    printArray(arr, size);

    delete[] arr;
    return 0;
}