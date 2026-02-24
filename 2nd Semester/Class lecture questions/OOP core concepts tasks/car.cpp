#include <iostream>
#include <string>
using namespace std;

class Car
{
    string make, model;
    long year, speed;

public:
    // Intializer list
    Car(string mk, string md, long yr) : make(mk), model(md), year(yr), speed(0) {}

    // setter
    void Set_Speed(double s = 10) { speed = s; }

    // Getter
    double get_speed(void) { return speed; }
    string get_model(void) { return model; }

    // Methods
    void Accelerate(double);
    void Brake(double);
    void Display(void);
    void Speed_Display(void);
};
void Car ::Speed_Display(void)
{
    if (speed > 0)
    {
        cout << model << " is travelling with " << speed << " m/s" << endl;
    }
    else if (speed <= 0)
    {
        cout << model << " is stopped." << endl;
    }
}
void Car ::Display(void)
{
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
}
void Car ::Accelerate(double a = 5)
{
    speed += a;
}
void Car ::Brake(double b = 5)
{
    speed -= b;
}
void PrintMenu(void);

int main()
{
    Car c1("Honda", "Civic", 2009);
    int choice;
    while (true)
    {
        PrintMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "----------------------" << endl;
            c1.Display();
            cout << "----------------------" << endl;
            break;
        case 2:
            double speed;
            cout << "----------------------" << endl;
            cout << "Enter speed in m/s: ";
            cin >> speed;
            c1.Set_Speed(speed);
            cout << "The speed of " << c1.get_model() << " is now " << c1.get_speed() << " m/s" << endl;
            cout << "----------------------" << endl;
            break;
        case 3:
            c1.Speed_Display();
            break;
        case 4:
            double acc;
            cout << "----------------------" << endl;
            cout << "Enter accelerating power: ";
            cin >> acc;
            c1.Accelerate(acc);
            cout << c1.get_model() << " is accelerated by " << acc << " m/s" << endl;
            cout << "----------------------" << endl;
            break;
        case 5:
            double de_acc;
            cout << "----------------------" << endl;
            cout << "Enter decelerating power: ";
            cin >> de_acc;
            c1.Brake(de_acc);
            cout << c1.get_model() << " is decelerated by " << de_acc << " m/s" << endl;
            cout << "----------------------" << endl;
            break;

        case 6:
            cout << "----------------------" << endl;
            cout << "Exiting from program...";
            return 0;

        default:
            cout << "----------------------" << endl;
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
void PrintMenu(void)
{
    cout << "1 - Display features" << endl;
    cout << "2 - Set Speed" << endl;
    cout << "3 - Display Speed" << endl;
    cout << "4 - Accelerate" << endl;
    cout << "5 - Break" << endl;
    cout << "6 - Exit" << endl;
    cout << "choose choice: ";
}
