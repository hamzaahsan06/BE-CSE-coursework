#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string Name_;
    string author_;
    string ISBN_;

public:
    // Setters
    void setName(string name) { Name_ = name; }
    void setName(string author) { author_ = author; }
    void setName(string ISBN) { ISBN_ = ISBN; }

    // method(s)
    void Display(void);
};
void Book ::Display(void)
{
    cout << "Name : " << Name_ << endl;
    cout << "Author : " << author_ << endl;
    cout << "ISBN : " << ISBN_ << endl;
}