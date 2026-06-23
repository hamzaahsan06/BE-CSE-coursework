#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(const string &n) : name(n) {}

    virtual void introduce()
    {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person
{
protected:
    string studentID;

public:
    Student(const string &n, const string &sid)
        : Person(n), studentID(sid) {}
};

class Teacher : virtual public Person
{
protected:
    string employeeID;

public:
    Teacher(const string &n, const string &eid)
        : Person(n), employeeID(eid) {}
};

class TeachingAssistant : public Student, public Teacher
{
public:
    TeachingAssistant(const string &name, const string &sid, const string &eid)
        : Person(name), Student(name, sid), Teacher(name, eid) {}

    void introduce() override
    {
        cout << "Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Employee ID: " << employeeID << endl;
    }
};

int main()
{
    TeachingAssistant ta("Hamza", "130", "180");
    ta.introduce();

    return 0;
}
/*
Output:
Name: Hamza
Student ID: 130
Employee ID: 180
*/

