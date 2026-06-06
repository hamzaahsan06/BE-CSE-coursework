#include <iostream>
using namespace std;

class TimerOverflowException
{
    string message;

public:
    TimerOverflowException(string message) : message(message) {}

    string what() const
    {
        return message;
    }
};
class Timer
{
    int Hour;
    int Minute;
    int Second;

public:
    Timer() : Hour(0), Minute(0), Second(0) {}

    void Tick()
    {
        Second++;

        if (Second == 60)
        {
            Second = 0; // starts for next minute.
            Minute++;
            if (Minute == 60)
            {
                Minute = 0; // starts for next hour.
                Hour++;
                if (Hour == 24)
                {
                    throw TimerOverflowException("Timer overflow");
                }
            }
        }
    }
};

int main()
{
    Timer t;
    try // Tick() may throw an exception when timer overflows, so it is placed inside try block
    {
        while (true)
        {
            t.Tick();
        }
    }
    catch (const TimerOverflowException &e) // catches the throw statement written inside tick() method
    {
        cerr << e.what() << endl;
    }
}
// Output: Timer overflow.