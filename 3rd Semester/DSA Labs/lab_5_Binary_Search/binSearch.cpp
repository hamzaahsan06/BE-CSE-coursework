#include <iostream>
using namespace std;

int BinSearch(int data[], int size, int element, int &comparisons)
{
    int beg = 0;
    int end = size - 1;
    int mid = int((beg + end) / 2);

    comparisons = 0;

    while (beg <= end && data[mid] != element)
    {
        comparisons++;

        if (element < data[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }

        mid = int((beg + end) / 2);
    }

    if (beg <= end)
    {
        comparisons++;
    }

    int location = -1;

    if (beg <= end && data[mid] == element)
    {
        location = mid;
    }

    return location;
}

int main()
{
    int size;
    cout << "Enter Size of array: \n>";
    cin >> size;
    int *arr = new int[size];

    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Best Case
    int comparisons;
    int location;

    cout << "\n--- Best Case ---\n";

    int bestItem = arr[size / 2];

    location = BinSearch(arr, size, bestItem, comparisons);

    cout << "Searching for: " << bestItem << endl;
    cout << "Found at index: " << location << endl;
    cout << "Comparisons: " << comparisons << endl;

    // Worst Case
    cout << "\n--- Worst Case ---\n";

    int worstItem = -1; // assuming -1 is not in the array

    location = BinSearch(arr, size, worstItem, comparisons);

    cout << "Searching for: " << worstItem << endl;
    cout << "Result: ";

    if (location == -1)
        cout << "Not found\n";
    else
        cout << "Found at index " << location << endl;

    cout << "Comparisons: " << comparisons << endl;

    // Average Case
    cout << "\n--- Average Case ---\n";

    int averageItem = arr[size / 2 + 1];

    location = BinSearch(arr, size, averageItem, comparisons);

    cout << "Searching for: " << averageItem << endl;
    cout << "Found at index: " << location << endl;
    cout << "Comparisons: " << comparisons << endl;
}