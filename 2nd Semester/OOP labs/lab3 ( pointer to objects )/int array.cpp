#include <iostream>
using namespace std;

class my_class
{
    int size; // represent the size of array
    int *ptr; // represent the address of the first element of the array.

public:
    // constructor(s)
    my_class(int);          // parametrized constructor
    my_class(const my_class &obj); // copy constructor
        // Destructor
        ~my_class()
    {
        delete[] ptr;
        cout << "Destructor called. Memory of array deallocated" << endl;
    }

    // Method(s)
    void InsertElements(void);
    void sum(void);
};
my_class ::my_class(int s)
{
    size = s;
    ptr = new int[size]; // array created dynamically
    cout << "Integer array with size of " << size << " is created" << endl;
}

my_class ::my_class(const my_class &obj) // deep copy.
{
    size = obj.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = obj.ptr[i];
    }
}
void my_class ::InsertElements(void)
{
    int element;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        *(ptr + i) = element;
    }
}

void my_class ::sum(void)
{
    long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(ptr + i);
    }

    cout << "The sum of elements is: " << sum << endl;
}

int main()
{
    int size;
    cout << "Enter size of 1st array: ";
    cin >> size;
    my_class arr1(size);
    arr1.InsertElements();
    arr1.sum();
    cout << "Copying elements of 1st array into 2nd array" << endl;
    my_class arr2(arr1); // Invoking copy constructor
    arr2.sum();
    return 0;
}
/* --- Output ---
Enter size of 1st array: 3
Integer array with size of 3 is created
Enter element 1: 2
Enter element 2: 4
Enter element 3: 6
The sum of elements is: 12
Copying elements of 1st array into 2nd array  
The sum of elements is: 12
Destructor called. Memory of array deallocated
Destructor called. Memory of array deallocated*/
