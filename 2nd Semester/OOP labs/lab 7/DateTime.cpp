#include <iostream>
using namespace std;
class DateTime
{
private:
    int month, year, day, hours, minutes, seconds;

public:
    // default constructor
    DateTime();
    // setters
    void SetValue(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void SetValue(int day, int month, int year, int hour)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        this->hours = hour;
    }
    void SetValue(int day, int month, int year, int hour, int minutes)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        this->hours = hour;
        this->minutes = minutes;
    }
    void SetValue(int day, int month, int year, int hour, int minutes, int seconds)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        this->hours = hour;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    void Display()
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
        cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }
};

DateTime::DateTime()
{
    month = 0;
    year = 0;
    day = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
}

int main()
{
    DateTime date;
    date.SetValue(10,10,2006);
    date.Display();

    date.SetValue(10,10,2006,11);
    date.Display();

    date.SetValue(10,10,2006,11,15);
    date.Display();

    date.SetValue(10,10,2006,11,15,20);
    date.Display();

    return 0;

}
