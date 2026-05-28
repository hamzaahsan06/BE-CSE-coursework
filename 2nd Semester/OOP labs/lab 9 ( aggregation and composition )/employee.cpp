// ----------- Q2 -------------

#include <iostream>
#include <cstring>
using namespace std;

class Salary
{
    float Gross_pay;
    float Deductions;
    float Net_pay;

public:
    Salary(float Gpay = 0, float Ded = 0)
    {
        Gross_pay = Gpay;
        Deductions = Ded;
        Net_pay = Gross_pay - Deductions;
    }

    void Display() const
    {
        cout << "Salary: " << Net_pay << endl;
    }
};
class Date
{
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void Display() const
    {
        cout << "Date : " << day << " / " << month << " / " << year << endl;
    }
};

class Employee
{
    int empNumber;
    char *name;
    Salary salary;
    Date date_of_joining;

public:
    Employee(int empNumber, char *n, float Gpay = 0, float Ded = 0, int day = 1, int month = 1, int year = 2000) : date_of_joining(day, month, year),
                                                                                                                   salary(Gpay, Ded)
    {
        this->empNumber = empNumber;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    ~Employee()
    {
        delete[] name; // Free dynamically allocated memory for name.
    }

    void Display() const
    {
        cout << "Employee Number : " << empNumber << endl;
        cout << "Name : " << name << endl;
        salary.Display();
        cout << "Date of joining: " << endl;
        date_of_joining.Display();
    }
};

int main()
{
    cout << "Enter Employee Information\n";

    int empNo;
    char name[100];
    float gross, ded;
    int d, m, y;

    cout << "Enter Employee Number: ";
    cin >> empNo;

    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, 100);

    cout << "Enter Gross Salary: ";
    cin >> gross;

    cout << "Enter Deductions: ";
    cin >> ded;

    cout << "Enter Date of Joining (day month year): ";
    cin >> d >> m >> y;

    // Creating object
    Employee e(empNo, name, gross, ded, d, m, y);

    cout << "\n----- Employee Details -----\n";
    e.Display();

    return 0;
}

/*
Output

Enter Employee Information
Enter Employee Number: 127
Enter Name: Hamza
Enter Gross Salary: 78000
Enter Deductions: 8000
Enter Date of Joining (day month year): 10 10 2020

----- Employee Details -----
Employee Number : 127
Name : Hamza
Salary: 70000
Date of joining:
Date : 10 / 10 / 2020

*/
