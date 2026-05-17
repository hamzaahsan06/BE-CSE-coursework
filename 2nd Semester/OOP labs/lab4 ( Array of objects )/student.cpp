#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    // Attributes
    char *name_; // Used to store the starting address of string.
    int Roll_;
    double marks_[5];
    float percentage_;

public:
    // Constructors
    Student();                   // Input Constructor
    Student(char *s, int r);     // parametrized constructor
    Student(const Student &obj); // copy constructor ( deep copy )
    // Destructor
    ~Student()
    {
        delete[] name_; // Frees the heap memory for the name string
        // Other attributes are automatically cleaned up because they are on stack.
    }
    // getters
    char *get_name() const { return name_; } // Returns the starting address of name, which is recieved by char pointer.
    int get_roll() const { return Roll_; }
    double get_marks(int index) const { return marks_[index - 1]; }
    // Setters
    void set_name(char *n)
    {
        delete[] name_;
        name_ = new char[strlen(n) + 1];
        strcpy(name_, n);
    }
    void set_roll(int r) { Roll_ = r; }
    void set_marks(int n)
    {
        double num;
        cout << "Enter new marks for test " << n << " : ";
        cin >> num;
        marks_[n - 1] = num;
    }
    // methods
    void calc_percent();
    void grade();
    void display();
    double max_marks();
};
Student ::Student(char *s, int r) // the parameter (s) is used to locate the starting address of string which is passed to it.
{
    name_ = new char[strlen(s) + 1];
    strcpy(name_, s);
    Roll_ = r;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter marks for test no." << i + 1 << " : " << endl;
        cin >> marks_[i];
    }
    percentage_ = 0;
}
Student ::Student()
{
    char temp[80]; // Temporary buffer to read input before dynamic allocation
    cout << "Enter name: ";
    cin >> temp;
    name_ = new char[strlen(temp) + 1];
    strcpy(name_, temp);
    cout << "Enter roll number: ";
    cin >> Roll_;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter marks for test no." << i + 1 << " : ";
        cin >> marks_[i];
    }
    percentage_ = 0;
}
Student::Student(const Student &obj)
{
    name_ = new char[strlen(obj.name_) + 1];
    strcpy(name_, obj.name_);
    Roll_ = obj.Roll_;
    for (int i = 0; i < 5; i++)
    {
        marks_[i] = obj.marks_[i];
    }
    percentage_ = obj.percentage_;
}
void Student ::calc_percent()
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += marks_[i];
    }
    percentage_ = (sum / 500) * 100;
}
void Student ::grade()
{
    calc_percent();
    cout << "Percentage: " << percentage_ << "%\n";
    if (percentage_ >= 80)
        cout << "Grade: A\n";
    else if (percentage_ >= 60)
        cout << "Grade: B\n";
    else if (percentage_ >= 50)
        cout << "Grade: C\n";
    else
        cout << "Grade: F\n";
}
void Student ::display()
{
    cout << "Name: " << name_ << endl;
    cout << "Roll Number: " << Roll_ << endl;
    grade();
    cout << "Highest marks : " << max_marks() << endl;
}
double Student ::max_marks()
{
    double max = 0;
    for (int i = 0; i < 5; i++)
    {
        if (marks_[i] > max)
        {
            max = marks_[i];
        }
    }
    return max;
}
int main()
{
    Student *s;         // Pointer to dynamic array of Student objects
    s = new Student[5]; // calls input value constructor.
    for (int i = 0; i < 5; i++)
    {
        cout << "Details of student " << i + 1 << endl;
        s[i].display();
        cout << "------------------------" << endl;
    }
    delete[] s;
}
