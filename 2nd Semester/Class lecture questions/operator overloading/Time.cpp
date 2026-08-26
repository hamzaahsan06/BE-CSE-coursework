#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minutes;

public:
    Time(int h = 0, int m = 0)
    {
        hour = h;
        minutes = m;
    }

    void Normalize()
    {
        hour += minutes / 60;
        minutes += minutes % 60;
    }

    Time operator+(Time &t)
    {
        Time temp;

        temp.hour = this->hour + t.hour;
        temp.minutes = this->minutes + t.minutes;

        temp.Normalize();

        return temp;
    }
    Time operator-(Time &t)
    {
        Time temp;

        temp.hour = this->hour - t.hour;
        temp.minutes = this->minutes - t.minutes;

        temp.Normalize();

        return temp;
    }

};