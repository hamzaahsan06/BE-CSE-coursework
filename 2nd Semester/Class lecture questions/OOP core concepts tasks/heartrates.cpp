#include <iostream>
#include <string>
using namespace std;

class DOB // class used to store Date of birth of a person
{

private:
    string month;
    int day;
    long year;

public:
    // constructor
    DOB(string m, int d, long y) : month(m), day(d), year(y) {}
    DOB(const DOB &obj)
    {
        month = obj.month;
        day = obj.day;
        year = obj.year;
    }
    DOB() {}
    // Setters
    void set_month(string m) { month = m; }
    void set_day(int d) { day = d; }
    void set_year(long y) { year = y; }
    // Getters
    string get_month(void) const { return month; }
    int get_day(void) const { return day; }
    long get_year(void) const { return year; }
    // methods
    void Display();
};
void DOB ::Display() // Defining display function for class DOB
{
    cout << "Year of birth: " << year << endl;
    cout << "Month of birth: " << month << endl;
    cout << "Day of birth: " << day << endl;
}

class HeartRates // class used to calculate Heart rates of a person
{
private:
    string First_name_;
    int ID_;
    DOB birth_;

public:
    // Constructor
    HeartRates(string, int, DOB);
    // setters
    void Set_name(string n) { First_name_ = n; }
    void Set_ID(int roll) { ID_ = roll % 10; } // Id is the third digit of a roll number from right }
    void Set_Date_of_birth(DOB obj) { birth_ = obj; }
    // getters
    string get_name() const { return First_name_; }
    int get_ID() const { return ID_; }
    DOB get_birth() const { return birth_; }

    // methods
    int getAge(void);
    int getMaximumHeartRate();
    void getTargetHeartRate(float &, float &);
    void Display(void);
};
HeartRates ::HeartRates(string name, int roll, DOB obj)
{
    First_name_ = name;
    birth_ = obj;    // Invoke copy constructor of class DOB.
    ID_ = roll % 10; // Id is the third digit of a roll number ( from left ).
}
int HeartRates ::getAge(void)
{
    DOB temp;
    temp = get_birth();            // stores Date of birth in a temporary variable
    return 2026 - temp.get_year(); // Subtracts person year of birth with 2026 to calculate person's age in year.
}
int HeartRates ::getMaximumHeartRate()
{
    return 220 - getAge(); // returns maximum heart rate in beats per minute
}
void HeartRates ::getTargetHeartRate(float &low, float &high) // Receive variables by refrence and updates thier values
{
    float fifty_per, eighty_five_per;
    low = 0.50 * getMaximumHeartRate();
    high = 0.85 * getMaximumHeartRate();
}
void HeartRates ::Display(void) // Defining display function for class HeartRates
{

    cout << "First Name: " << First_name_ << endl;
    cout << "ID: " << ID_ << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Maximum Heartrate: " << getMaximumHeartRate() << " beats per minute." << endl;
    float low, high; // Used to store range of target heartrate
    getTargetHeartRate(low, high);
    cout << "Target heart rate range: " << low << " - " << high << " beats per minute." << endl;
}
int main()
{
    string name;
    int roll;
    string month;
    long year;
    int day;

    cout << "=========== Heartrate Calculation Application ===========" << endl;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your roll number: ";
    cin >> roll;
    cout << "Type your month of birth: ";
    cin >> month;
    cout << "Type your day of birth: ";
    cin >> day;
    cout << "Type your year of birth: ";
    cin >> year;

    DOB obj(month, day, year);        // Creates an instance of class DOB and stores date of birth
    HeartRates obj1(name, roll, obj); // creates an instance of class heart rates and stores information of a person
    obj.Display();                    // Displaying date of birth
    obj1.Display();                   // Displaying heart rates info of a person
}