#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;

int *ArrayInput(int size)
{
    int *arr = new int[size + 1];
    for (int i = 1; i <= size; i++) // since 0 index is ignored so last index is equals to size.
    {
        cout << "Enter element " << i << " : ";
        cin >> arr[i];
    }

    return arr;
}

void InsertionSort(int arr[], int size)
{
    arr[0] = -999;
    int temp;
    int ptr;

    for (int k = 2; k <= size; k++) // starting from 2nd index assuming that element at 1st index is already sorted
    {
        temp = arr[k];
        ptr = k - 1;
        while (temp < arr[ptr])
        {
            arr[ptr + 1] = arr[ptr]; // bigger element moves forward
            ptr--;                   // checks in entire sorted array
        }
        arr[ptr + 1] = temp; // Sets the temp value in the correct position of sorted array
    }
}

void ShellSort(int arr[], int size)
{
    int key, j;

    // Step 1: starting gap
    int k = size / 2;

    // Step 2: keep going while the gap is greater than 0
    while (k > 0)
    {
        // 1-based: i runs from k+1 to N
        // (0-based version would be k to N-1)
        for (int i = k + 1; i <= size; i++)
        {
            key = arr[i];
            j = i;

            // 1-based: j - k must stay >= 1, so the condition is j > k
            // (0-based version would be j >= k)
            while (j > k && arr[j - k] > key)
            {
                swap(arr[j], arr[j - k]);
                j = j - k; // move back by one gap
            }
        }

        // Step e: shrink the gap after one full pass
        k = (int)(k / 2.2);
    }

    // k hit 0 before every sublist was fully sorted, so the array is only
    // nearly sorted. Insertion sort finishes it quickly.
    InsertionSort(arr, size);
}

// Helper function to measure execution time cleanly
double measureTime(void (*sortFunc)(int[], int), int arr[], int size) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr, size);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, micro>(end - start).count();
}

int main()
{
    // ------------------------------------------------------------------
    // Case i: 8 Elements (with duplicates)
    // ------------------------------------------------------------------
    int test1[] = {0, 15, 8, 23, 8, 42, 16, 42, 4}; // 1-based indexing, size = 8
    int a1[9], a2[9];
    for (int i = 0; i <= 8; i++) { a1[i] = test1[i]; a2[i] = test1[i]; }

    cout << "=== Case i: 8 Elements (with duplicates) ===\n";
    cout << "Insertion Sort: " << measureTime(InsertionSort, a1, 8) << " us\n";
    cout << "Shell Sort:     " << measureTime(ShellSort, a2, 8) << " us\n\n";

    // ------------------------------------------------------------------
    // Case ii: 20 Elements (50% sorted)
    // ------------------------------------------------------------------
    int test2[21] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    int b1[21], b2[21];
    for (int i = 0; i <= 20; i++) { b1[i] = test2[i]; b2[i] = test2[i]; }

    cout << "=== Case ii: 20 Elements (50% sorted) ===\n";
    cout << "Insertion Sort: " << measureTime(InsertionSort, b1, 20) << " us\n";
    cout << "Shell Sort:     " << measureTime(ShellSort, b2, 20) << " us\n\n";

    // ------------------------------------------------------------------
    // Case iii: 100 Elements (completely random and unsorted)
    // ------------------------------------------------------------------
    int c1[101], c2[101];
    srand(42);
    for (int i = 1; i <= 100; i++) {
        int val = rand() % 500;
        c1[i] = val;
        c2[i] = val;
    }

    cout << "=== Case iii: 100 Elements (completely random) ===\n";
    cout << "Insertion Sort: " << measureTime(InsertionSort, c1, 100) << " us\n";
    cout << "Shell Sort:     " << measureTime(ShellSort, c2, 100) << " us\n";

    return 0;
}