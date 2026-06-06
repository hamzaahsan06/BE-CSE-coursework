#include <iostream>
#include <stdexcept>
using namespace std;

class DateException
{
private:
    string message;

public:
    DateException(string m) : message(m) {}
    string what() const { return message; }
};

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {}
    Date(int day, int month, int year) : day(day), month(month), year(year)
    {

        if (day <= 0 || day > 31 || month <= 0 || month > 12 || year <= 0)
        {
            throw DateException("Incorrect date."); // Throws an error and object is not created.
        }
    }
    void SetDate()
    {
        cout << "Enter date (DD MM YYYY)\n> ";
        cin >> day >> month >> year;

        if (day <= 0 || day > 31 || month <= 0 || month > 12 || year <= 0)
        {
            throw DateException("Incorrect date."); // Throws an error and values are not set.
        }
    }
};

int main()
{
    Date date;
    try
    {
        date.SetDate();
    }
    catch (DateException e)
    {
        cout << e.what();
    }
    return 0;
}
/*
Output

Enter date (DD MM YYYY)
> 10 14 2024
Incorrect date.

*/
