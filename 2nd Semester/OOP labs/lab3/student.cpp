#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    string name_;
    int RollNo_;
    float GPA_;

public:
    // constructor
    Student() {}

    // getters
    int get_roll()
    {
        return RollNo_;
    }

    // Setters
    void set_name(string name)
    {
        name_ = name;
    }

    void set_RollNo(int roll)
    {
        RollNo_ = roll;
    }

    void set_GPA(float gpa)
    {
        GPA_ = gpa;
    }

    void Display()
    {
        cout << "Name: " << name_ << endl;
        cout << "Roll Number: " << RollNo_ << endl;
        cout << "GPA: " << GPA_ << endl;
    }
};

void addRecords(void);
void DisplayRecords(void);
void SearchByRollNumber(void);
void PrintMenu(void);

Student students[10]; // Globaly allocate memory for 10 students using default constructor.
int main()
{
    int choice;
    while (true)
    {
        PrintMenu();
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            addRecords();
            break;
        case 2:
            DisplayRecords();
            break;
        case 3:
            SearchByRollNumber();
            break;
        case 4:
            cout << "Exiting from program" << endl;
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
void PrintMenu(void)
{
    cout << "1 - Add Record of students" << endl;
    cout << "2 - Display Record of students" << endl;
    cout << "3 - Search student from a roll number" << endl;
    cout << "4 - Exit" << endl;
    cout << "Choose Choice: ";
}
void addRecords(void)
{
    string name;
    int roll;
    float gpa;

    // for reading records (TASK 1)
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, name);
        students[i].set_name(name);
        cout << "Enter Roll Number of student " << i + 1 << ": ";
        cin >> roll;
        students[i].set_RollNo(roll);
        cout << "Enter GPA of student " << i + 1 << ": ";
        cin >> gpa;
        students[i].set_GPA(gpa);
        cin.ignore();
    }
    cout << "\nAll records added successfully!" << endl;
}
void DisplayRecords(void)
{
    cout << "\n=== All Student Records ===" << endl;
    // for displaying records
    for (int i = 0; i < 10; i++)
    {
        students[i].Display();
        cout << "-----------------" << endl;
    }
}
void SearchByRollNumber(void)
{
    int search_roll;
    Student *ptr;
    ptr = students;
    bool found = false;
    // Searching record by a roll number through pointers (TASK 2)
    cout << "Enter roll number to search for a student: ";
    cin >> search_roll;
    for (int i = 0; i < 10; i++)
    {
        if (ptr->get_roll() == search_roll)
        {
            ptr->Display();
            found = true;
            break;
        }
        else
        {
            ptr++;
        }
    }
    if (!found)
    {
        cout << "There is no student with roll number " << search_roll;
    }
}
/*  -------- OUTPUT -------
1 - Add Record of students
2 - Display Record of students
3 - Search student from a roll number
4 - Exit
Choose Choice: 1
Enter name of student 1: Hamza
Enter Roll Number of student 1: 130
Enter GPA of student 1: 4
Enter name of student 2: Qaseem
Enter Roll Number of student 2: 131
Enter GPA of student 2: 4
Enter name of student 3: Wasif
Enter Roll Number of student 3: 132
Enter GPA of student 3: 4
Enter name of student 4: Rayyan
Enter Roll Number of student 4: 34
Enter GPA of student 4: 4
Enter name of student 5: Tahir
Enter Roll Number of student 5: 35
Enter GPA of student 5: 3
Enter name of student 6: Uzair
Enter Roll Number of student 6: 36
Enter GPA of student 6: 3
Enter name of student 7: Ismail
Enter Roll Number of student 7: 37
Enter GPA of student 7: 4
Enter name of student 8: Osama
Enter Roll Number of student 8: 38
Enter GPA of student 8: 3
Enter name of student 9: Ahmad
Enter Roll Number of student 9: 39
Enter GPA of student 9: 4
Enter name of student 10: Daniyal
Enter Roll Number of student 10: 40
Enter GPA of student 10: 4

All records added successfully!
1 - Add Record of students
2 - Display Record of students
3 - Search student from a roll number
4 - Exit
Choose Choice: 2

=== All Student Records ===
Name: Hamza
Roll Number: 130
GPA: 4
-----------------
Name: Qaseem
Roll Number: 131
GPA: 4
-----------------
Name: Wasif
Roll Number: 132
GPA: 4
-----------------
Name: Rayyan
Roll Number: 34
GPA: 4
-----------------
Name: Tahir
Roll Number: 35
GPA: 3
-----------------
Name: Uzair
Roll Number: 36
GPA: 3
-----------------
Name: Ismail
Roll Number: 37
GPA: 4
-----------------
Name: Osama
Roll Number: 38
GPA: 3
-----------------
Name: Ahmad
Roll Number: 39
GPA: 4
-----------------
Name: Daniyal
Roll Number: 40
GPA: 4
-----------------
1 - Add Record of students
2 - Display Record of students
3 - Search student from a roll number
4 - Exit
Choose Choice: 3
Enter roll number to search for a student: 39
Name: Ahmad
Roll Number: 39
GPA: 4
1 - Add Record of students
2 - Display Record of students
3 - Search student from a roll number
4 - Exit
Choose Choice: 4
Exiting from program */