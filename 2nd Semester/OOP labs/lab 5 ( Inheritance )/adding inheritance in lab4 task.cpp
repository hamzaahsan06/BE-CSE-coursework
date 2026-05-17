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
    void set_Percentage(double sum, double total)
    {
        percentage_ = (sum / total) * 100;
    }
    // methods
    virtual void calc_percent(); // virtual keyword is used to achieve runtime binding
    void grade();
    void display();
    double max_marks(int Number_of_subjects = 5); // default value of subjects is 5
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
    set_Percentage(sum, 500);
}
void Student ::grade()
{
    calc_percent(); // Due to runtime binding, this fucntion is called, based on the object which is calling it.
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
    cout << "--------------------------" << endl;
    cout << "Name: " << name_ << endl;
    cout << "Roll Number: " << Roll_ << endl;
    grade();
    cout << "Highest marks : " << max_marks() << endl;
}
double Student ::max_marks(int tot_sub)
{
    double max = 0;
    for (int i = 0; i < tot_sub; i++)
    {
        if (marks_[i] > max)
        {
            max = marks_[i];
        }
    }
    return max;
}
class ScienceStudent : public Student
{
    double addPracticeCourse_;

public:
    ScienceStudent()
    { // after executing default input constructor of base class this default input constructor of derived class is called.
        cout << "Enter marks of additional practice course" << " : ";
        cin >> addPracticeCourse_;
    }
    // methods
    void calc_percent()
    {
        double sum = 0;
        for (int i = 1; i < 6; i++)
        {
            sum += get_marks(i);
        }
        sum += addPracticeCourse_;
        set_Percentage(sum, 650); // setting percentage using public setter of base class.
    }
    void display()
    {
        cout << "--------------------------" << endl;
        cout << "Name: " << get_name() << endl;
        cout << "Roll Number: " << get_roll() << endl;
        grade();
        cout << "Highest marks : " << max_marks(6) << endl;
    }
};
class ArtStudent : public Student
{
private:
    string Is_optional_course_taken;
    bool taken;
    double optional_course;

public:
    ArtStudent()
    { // after executing default input constructor of base class this default input constructor of derived class is called.
        cout << "Have you enrolled in optional course? (yes/no): " << endl;
        cin >> Is_optional_course_taken;
        if (Is_optional_course_taken == "Yes" || Is_optional_course_taken == "yes")
        {
            cout << "Enter marks of optional course" << " : ";
            cin >> optional_course;
            taken = true;
        }
        else
        {
            taken = false;
        }
    }
    // methods
    void calc_percent()
    {
        double sum = 0;
        for (int i = 1; i < 6; i++)
        {
            sum += get_marks(i);
        }
        if (taken == true)
        {

            sum += optional_course;
            set_Percentage(sum, 600);
        }
        else
        {
            set_Percentage(sum, 500);
        }
    }
    void display()
    {
        cout << "--------------------------" << endl;
        cout << "Name: " << get_name() << endl;
        cout << "Roll Number: " << get_roll() << endl;
        grade();
        if (taken == true)
        {
            cout << "Highest marks : " << max_marks(6) << endl; // if optional course is taken then total number of subjects are 6.
        }
        else
        {
            cout << "Highest marks : " << max_marks() << endl; // otherwise, total subjects are 5(default value).
        }
    }
};
int main()
{
    Student s;
    ScienceStudent s1;
    ArtStudent s2;
    s.display();
    s1.display();
    s2.display();
}
