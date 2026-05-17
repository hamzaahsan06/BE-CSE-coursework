#include <iostream>
#include <cstring>
using namespace std;
class Student
{
    char *name; // Used to store the starting address of string.
    int roll_num;
    double marks[5];
    float percent;

public:
    Student()
    {
        char temp[80]; // temporary array, storing space of 80 characters
        cout << "Enter name: " << endl;
        cin >> temp;                       // Reads character and store in temp till Whitespace or End of input.
        name = new char[strlen(temp) + 1]; // stores the memory for string. +1 because strlen dont goes till null.
        strcpy(name, temp);                // copies the \0 as well.
        cout << "Enter roll number: " << endl;
        cin >> roll_num;
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks for test no." << i + 1 << " : " << endl;
            cin >> marks[i];
        }
        percent = 0;
    }
    Student(char *s, int r) // the parameter (s) is used to locate the starting address of string which is passed to it.
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
        roll_num = r;
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks for test no." << i + 1 << " : " << endl;
            cin >> marks[i];
        }
        percent = 0;
    }
    Student(Student &s)
    {
        // deep copy
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        roll_num = s.roll_num;
        for (int i = 0; i < 5; i++)
        {
            marks[i] = s.marks[i];
        }
        percent = s.percent;
    }
    ~Student()
    {
        delete[] name; // Frees the heap memory for the name string
        // Other members (roll_num, marks, percent) are automatically cleaned up because they are on stack.
    }
    char *get_name() // Returns the starting address of name, which is recieved by char pointer.
    {
        return name;
    }
    int get_rollnum()
    {
        return roll_num;
    }
    double get_marks(int i)
    {
        return marks[i - 1];
    }
    void set_name(char *s)
    {
        delete[] name;
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }
    void set_roll(int r)
    {
        roll_num = r;
    }
    void set_marks(int n) // Receives index
    {
        double num;
        cout << "Enter new marks for test " << n << " : ";
        cin >> num;
        marks[n - 1] = num;
    }
    void calc_percent();
    void grade();
    void display();
};
void Student::calc_percent()
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += marks[i];
    }
    percent = (sum / 500) * 100;
}
void Student::grade()
{
    calc_percent();
    cout << "Percentage: " << percent << "%\n";
    if (percent >= 80)
        cout << "Grade: A\n";
    else if (percent >= 60)
        cout << "Grade: B\n";
    else if (percent >= 50)
        cout << "Grade: C\n";
    else
        cout << "Grade: F\n";
}
void Student::display()
{
    cout << "\nName: " << name; // prints characters from starting till last ( complete string )
    cout << "\nRoll No: " << roll_num << endl;
    grade();
}
int main()
{
    Student *s;
    s = new Student[2]; // calls input value constructor.
    for (int i = 0; i < 2; i++)
    {
        cout << "\nStudent " << i + 1 << " Details:\n";
        s[i].display();
    }
    cout << s[0].get_marks(2);
    delete[] s;
}