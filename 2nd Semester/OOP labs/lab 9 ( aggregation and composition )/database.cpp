// ----------- Q3 and Q4 -------------
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
    Salary &operator=(const Salary &other)
    {
        this->Gross_pay = other.Gross_pay;
        this->Deductions = other.Deductions;
        this->Net_pay = other.Net_pay;

        return *this;
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
    Date &operator=(const Date &other)
    {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;

        return *this;
    }
};

class Employee
{
    int empNumber;
    char *name;
    Salary salary;
    Date date_of_joining;

public:
    Employee(int empNumber = 0, const char *n = "ABC", float Gpay = 0, float Ded = 0, int day = 1, int month = 1, int year = 2000) : date_of_joining(day, month, year),
                                                                                                                                     salary(Gpay, Ded)
    {
        this->empNumber = empNumber;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    Employee(const Employee &obj) : empNumber(obj.empNumber), salary(obj.salary), date_of_joining(obj.date_of_joining)
    {
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
    }
    Employee &operator=(const Employee &other) // To assign object of employee to other in delete employee logic
    {
        if (this != &other) // Check if addresses are different and prevent the loss of this object data.
        {
            delete[] name;
            empNumber = other.empNumber;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            salary = other.salary;
            date_of_joining = other.date_of_joining;
        }
        return *this;
    }

    // Setters

    void setEmpNumber(int empNumber)
    {
        this->empNumber = empNumber;
    }

    void setName(const char *n)
    {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void setSalary(float Gpay, float Ded)
    {
        salary = Salary(Gpay, Ded);
    }

    void setDate(int day, int month, int year)
    {
        date_of_joining = Date(day, month, year);
    }

    // Getters

    int getEmpNumber() const
    {
        return empNumber;
    }

    const char *getName() const
    {
        return name;
    }

    Salary getSalary() const
    {
        return salary;
    }

    Date getDateOfJoining() const
    {
        return date_of_joining;
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

class Database
{
private:
    Employee *arr;
    int size;
    int employee_count = 0;

public:
    Database()
    {
        cout << "Enter Size of array for employees record:\n> ";
        cin >> size;
        arr = new Employee[size];
    }

    int get_size() { return size; }
    Employee *get_arr() { return arr; }

    void Display()
    {
        for (int i = 0; i < employee_count; i++)
        {
            arr[i].Display();
            cout << "-----------------------------" << endl;
        }
    }
    void addEmp();
    void RemoveEmp();
    void searchEmp();
    ~Database()
    {
        delete[] arr; // To call destructor of each object.
    }
};
void Database::addEmp()
{
    if (employee_count < size)
    {
        int empNo;
        char name[100];
        float gross, ded;
        int d, m, y;

        cout << "Enter information for employee number: " << employee_count + 1 << endl;
        cout << "-----------------------------------------------" << endl;

        cout << "Enter Employee Number: ";
        cin >> empNo;
        arr[employee_count].setEmpNumber(empNo);

        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 100);
        arr[employee_count].setName(name);

        cout << "Enter Gross Salary: ";
        cin >> gross;

        cout << "Enter Deductions: ";
        cin >> ded;
        arr[employee_count].setSalary(gross, ded);

        cout << "Enter Date of Joining (day month year): ";
        cin >> d >> m >> y;
        arr[employee_count].setDate(d, m, y);

        employee_count++;
    }
    else
    {
        cout << "No more space for employees." << endl;
    }
}
void Database::RemoveEmp()
{
    int id;
    int index;
    bool flag = false;

    cout << "Enter id to delete an employee\n> ";
    cin >> id;

    for (int i = 0; i < employee_count; i++)
    {
        if (id == arr[i].getEmpNumber())
        {
            index = i;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "Employee with id " << id << " not found." << endl;
        return;
    }

    employee_count--;
    for (int i = index; i < employee_count; i++)
    {
        arr[i] = arr[i + 1];
    }
    cout << "Employee with id " << id << " is removed from database." << endl;
}
void Database::searchEmp()

{
    int id;
    bool flag = false;

    cout << "Enter id to search an employee\n> ";
    cin >> id;

    for (int i = 0; i < employee_count; i++)
    {
        if (id == arr[i].getEmpNumber())
        {
            cout << "Employee's detail\n";
            cout << "----------------------" << endl;
            arr[i].Display();
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "Employee with id " << id << " not found." << endl;
        return;
    }
}

int main()
{
    Database db;

    int choice;

    do
    {
        cout << "\n===== Employee Database =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Display All Employees\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            db.addEmp();
            break;

        case 2:
            db.RemoveEmp();
            break;

        case 3:
            db.searchEmp();
            break;

        case 4:
            db.Display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

/* Output

Enter Size of array for employees record:
> 3

===== Employee Database =====
1. Add Employee
2. Remove Employee
3. Search Employee
4. Display All Employees
0. Exit
Enter choice: 1
Enter information for employee number: 1
-----------------------------------------------
Enter Employee Number: 1
Enter Name: Tahir
Enter Gross Salary: 89000
Enter Deductions: 9000
Enter Date of Joining (day month year): 10 10 2009

===== Employee Database =====
1. Add Employee
2. Remove Employee
3. Search Employee
4. Display All Employees
0. Exit
Enter choice: 1
Enter information for employee number: 2
-----------------------------------------------
Enter Employee Number: 2
Enter Name: Yasir
Enter Gross Salary: 87000
Enter Deductions: 8000
Enter Date of Joining (day month year): 8 9 2016

===== Employee Database =====
1. Add Employee
2. Remove Employee
3. Search Employee
4. Display All Employees
0. Exit
Enter choice: 1
Enter information for employee number: 3
-----------------------------------------------
Enter Employee Number: 3
Enter Name: Hamza
Enter Gross Salary: 90000
Enter Deductions: 8000
Enter Date of Joining (day month year): 10 10 2023

===== Employee Database =====
1. Add Employee
2. Remove Employee
3. Search Employee
4. Display All Employees
0. Exit
Enter choice: 4
Employee Number : 1
Name : Tahir
Salary: 80000
Date of joining: 
Date : 10 / 10 / 2009
-----------------------------
Employee Number : 2
Name : Yasir
Salary: 79000
Date of joining: 
Date : 8 / 9 / 2016
-----------------------------
Employee Number : 3
Name : Hamza
Salary: 82000
Date of joining: 
Date : 10 / 10 / 2023
-----------------------------

===== Employee Database =====
1. Add Employee
2. Remove Employee
3. Search Employee
4. Display All Employees
0. Exit
Enter choice: 2
Enter id to delete an employee
> 2
Employee with id 2 is removed from database.

===== Employee Database =====
1. Add Employee
2. Remove Employee
3. Search Employee
4. Display All Employees
0. Exit
Enter choice: 3
Enter id to search an employee
> 3
Employee's detail
----------------------
Employee Number : 3
Name : Hamza
Salary: 82000
Date of joining: 
Date : 10 / 10 / 2023

===== Employee Database =====
1. Add Employee
2. Remove Employee
3. Search Employee
4. Display All Employees
0. Exit
Enter choice: 0
Exiting...

*/
