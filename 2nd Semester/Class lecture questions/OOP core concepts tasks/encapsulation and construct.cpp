// Review class notes till abstraction first.
#include <iostream>
#include <string>
using namespace std;
class Date
{
private:
    // Attributes
    int day_, month_, year_;
    string period_;

public:
    // constructor
    Date() {}            // Default
    Date(int, int, int); // parametrized
    // Setters
    void SetYear(int);
    void SetMonth(int);
    void SetDay(int);
    // Behaviors
    void addYear(int);
    void addMonth(int);
    void addDay(int);
    void Display(void);
};
// --------------------- def for parametrized constructor -----------------------
Date ::Date(int d, int m, int y)
{
    SetDay(d); // the given date is first goes through logic of setter function
    SetMonth(m);
    SetYear(y);
}
// --------------------- def for Setters -----------------------
// the day of the month, restricted to [1..31]
void Date ::SetDay(int n)
{
    if (n >= 1 && n <= 31)
    {
        day_ = n;
    }
    else
    {
        cout << "Given day is incorrect" << endl;
    }
}
// the month of the year, restricted to [1..12]
void Date ::SetMonth(int n)
{
    if (n >= 1 && n <= 12)
    {
        month_ = n;
    }
    else
    {
        cout << "Given month is incorrect" << endl;
    }
}
// positive = AD, negative = BC, restricted to non-zero
void Date ::SetYear(int n)
{
    if (n == 0)
    {
        cout << "Given year is incorrect" << endl;
        return;
    }
    else if (n > 0)
    {
        year_ = n;
        period_ = "AD";
    }
    else
    {
        year_ = -n;
        period_ = "BC";
    }
}
// --------------------- def for behaviors -----------------------
void Date ::addYear(int n)
{
    if (n > 0)
    {
        year_ += n;
    }
    else
    {
        n = -n;
        year_ += n;
    }
}
void Date ::addMonth(int n)
{
    month_ += n;
}
void Date ::addDay(int n)
{

    day_ += n;
}
void Date ::Display(void)
{
    cout << "\nDay: " << day_ << endl;
    cout << "Month: " << month_ << endl;
    cout << "Year: " << year_ << " " << period_ << endl;
}

int main()
{
    Date d1(4, 6, 2003);
    Date d2(3, 7, -90);
    d1.Display();
    d2.Display();
}