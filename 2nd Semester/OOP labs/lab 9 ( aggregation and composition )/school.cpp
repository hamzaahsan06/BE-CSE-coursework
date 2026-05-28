#include <iostream>
#include <string>

using namespace std;

class Teacher
{
public:
    string name;
    string course;

    Teacher(string name, string course)
    {
        this->name = name;
        this->course = course;
    }

    string get_name() { return name; }
    string get_course() { return course; }
};

class Department
{
public:
    string deptName;
    int NumOfTeachers;
    // Aggregation: Department holds pointers to Teacher objects
    Teacher *teachers[3];

    Department()
    {
        deptName = "XYZ";
        NumOfTeachers = 0;
        for (int i = 0; i < 3; i++)
        {
            teachers[i] = nullptr;
        }
    }

    void set_name(string name)
    {
        deptName = name;
    }

    void addTeacher(Teacher *t)
    {
        if (NumOfTeachers < 3)
        {
            teachers[NumOfTeachers] = t;
            NumOfTeachers++;
        }
        else
        {
            cout << "Staff room full" << endl;
        }
    }

    void ShowDepartment() const
    {
        cout << "Name: " << deptName << endl;
        cout << "Number of teachers: " << NumOfTeachers << endl;
        for (int i = 0; i < NumOfTeachers; i++)
        {
            cout << "Teacher " << i << " name: " << teachers[i]->get_name() << endl;
            cout << "Teacher " << i << " course: " << teachers[i]->get_course() << endl;
            cout << "\n";
        }
    }
};

class School
{
public:
    string address;
    // Composition: Departments are part of the School
    Department dep1;
    Department dep2;

    School(string add, Teacher &t1, Teacher &t2, Teacher &t3, Teacher &t4)
    {
        address = add;
        cout << "Write information of departments" << endl;

        string name;

        // Setup Department 1
        cout << "Info of department 1 \n";
        cout << "Enter name: ";
        cin >> name;
        dep1.set_name(name);
        dep1.addTeacher(&t1);
        dep1.addTeacher(&t2);

        // Setup Department 2
        cout << "Info of department 2 \n";
        cout << "Enter name: ";
        cin >> name;
        dep2.set_name(name);
        dep2.addTeacher(&t3);
        dep2.addTeacher(&t4);
    }

    void displaySchoolInfo()
    {
        cout << "--- School Details ---" << endl;
        cout << "Address: " << address << endl;
        dep1.ShowDepartment();
        dep2.ShowDepartment();
    }
};

int main()
{
    // Creating Teacher objects first (Aggregation requirement)
    Teacher t1("Alice", "Math");
    Teacher t2("Bob", "Physics");
    Teacher t3("Charlie", "History");
    Teacher t4("Diana", "Art");

    // Creating School object
    School s1("123 Education Lane", t1, t2, t3, t4);

    s1.displaySchoolInfo();

    return 0;
}