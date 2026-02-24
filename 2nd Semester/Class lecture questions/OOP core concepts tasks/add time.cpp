#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
    int hours, minutes, seconds;

public:
    // constructor
    Time(int h = 0, int m = 0, int s = 0);
    // method
    Time Add(const Time &);
    void Display(void);
};
// constructor
Time ::Time(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}
// method
Time Time ::Add(const Time &t)
{
    Time result;
    result.seconds = t.seconds + seconds; // add seconds of both times
    result.minutes = result.seconds / 60; // if seconds are equivalent to 1 minute then increment minutes
    result.seconds %= 60;                 // save seconds after taking remainder with 60

    result.minutes += minutes + t.minutes; // add minutes of both times in resultant object.
    result.hours += result.minutes / 60;   // if minutes are equivalent to 1 hour then increment hours
    result.minutes %= 60;                  // save minutes after taking remainder with 60

    result.hours += hours + t.hours; // add hours of both times in resultant object
    return result;
}
void Time ::Display(void)
{
    cout << hours << " : " << minutes << " : " << seconds << endl;
}
int main()
{
    Time t1(1, 30, 40);
    Time t2(4, 60, 60);
    Time t3 = t2.Add(t1);

    t1.Display();
    t2.Display();
    t3.Display();
}