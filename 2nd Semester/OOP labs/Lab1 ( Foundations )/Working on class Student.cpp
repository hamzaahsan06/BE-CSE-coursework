// ---------- exercise 2 ----------
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
    string name;
    string roll;
    vector<int> marks;

public:
    // Setters
    void set_name(string n)
    {
        name = n;
    }

    void set_roll(string rollNO)
    {
        roll = rollNO;
    }

    void set_marks(vector<int> ObtMarks)
    {   
        if (ObtMarks.size() == 3)
        {
            marks = ObtMarks;
        }
    }

    // Getters
    string get_name()
    {
        return name;
    }

    string get_roll()
    {
        return roll;
    }

    vector<int> get_marks()
    {
        return marks;
    }

    // Methods declaration
    void print_student();
    float Avg();
};

// Methods definition
void Student :: print_student()
{
    cout << "Student name: " << name << endl;
    cout << "Roll number: " << roll << endl;
    cout << "Marks: " << endl;
    cout << "Quiz1: " << marks[0] << endl;
    cout << "Quiz2: " << marks[1] << endl;
    cout << "Quiz3: " << marks[2] << endl;
}
float Student ::Avg()
{
    float avg = (marks[0] + marks[1] + marks[2]) / 3.0;
    return avg;
}

// main
int main()
{
    int n;
    Student s1;
    string name;
    string roll;
    vector<int> marks;
    float avg;

    cout << "Enter name of the student: ";
    getline(cin, name);
    s1.set_name(name);

    cout << "Enter roll number of " << s1.get_name() << ": ";
    getline(cin, roll);
    s1.set_roll(roll);

    for (int i = 0; i < 3; i++)
    {
        int m;
        cout << "Enter marks of subject " << i + 1 << ": ";
        cin >> m;
        marks.push_back(m);
    }
    s1.set_marks(marks);

    s1.print_student();

    avg = s1.Avg();
    cout << "Average marks of three quizes: " << avg << endl;
}