#include <iostream>
#include <stdexcept>
using namespace std;

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
                    throw logic_error("Timer overflow.");
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
    catch (const logic_error &e) // catches the throw statement written inside tick() method
    {
        cerr << e.what() << endl;
    }
}
// Output: Timer overflow.