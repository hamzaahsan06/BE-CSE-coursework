#include <iostream>
#include <cstring>
using namespace std;

class myclass
{
    int data[2];

public:
    int *p;

public:
    myclass()
    {
        p = data;
    }
    void InsertValues(void);
    void DisplayValues(void);
};
void myclass ::InsertValues(void)
{
    int element;
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        p[i] = element;
    }
    cout << "All elements inserted" << endl;
}
void myclass ::DisplayValues(void)
{
    cout << "--- Elements ---" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "Element " << i + 1 << ": " << p[i] << endl;
    }
}
int main()
{
    myclass *cp;
    cp = new myclass[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Input elements of object " << i + 1 << endl;
        cp[i].InsertValues();
        cout << "Displaying elements of object " << i + 1 << endl;
        cp[i].DisplayValues();
    }

    return 0;
}
/* --- OUTPUT ---
Input elements of object 1
Enter element 1: 1
Enter element 2: 2
All elements inserted
Displaying elements of object 1
--- Elements ---
Element 1: 1
Element 2: 2
Input elements of object 2
Enter element 1: 3
Enter element 2: 4
All elements inserted
Displaying elements of object 2
--- Elements ---
Element 1: 3
Element 2: 4
Input elements of object 3
Enter element 1: 5
Enter element 2: 6
All elements inserted
Displaying elements of object 3
--- Elements ---
Element 1: 5
Element 2: 6
*/