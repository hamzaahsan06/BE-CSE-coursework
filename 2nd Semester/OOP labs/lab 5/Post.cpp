#include <iostream>
using namespace std;
class Post
{
private:
    string name;
    string to;
    float StampCost;

public:
    // defualt constructor
    Post()
    {
        name = " ";
        to = " ";
        StampCost = 1;
    }
    // methods
    virtual void Read()
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter receiver's name: ";
        getline(cin, to);
        cout << "Enter stamp cost value: ";
        cin >> StampCost;
        cin.ignore();
    }
    virtual void Print()
    {
        cout << "Name : " << name << endl;
        cout << "To : " << to << endl;
        cout << "Stamp Cost : " << StampCost << " $ " << endl;
    }
    virtual float TotalCost() { return StampCost; }
};
class RegisteredPost : public Post
{
private:
    float weight;
    float RegistrationCost;

public:
    RegisteredPost()
    {
        weight = 20;
        RegistrationCost = 10;
    }
    void Read()
    {
        Post ::Read();
        cout << "Enter weight of the post: ";
        cin >> weight;
        cout << "Enter Registration cost of the post: ";
        cin >> RegistrationCost;
    }
    void Print()
    {
        Post ::Print();
        cout << "Weight : " << weight << " gram(s) " << endl;
        cout << "Registration Cost : " << RegistrationCost << " $ " << endl;
    }
    float TotalCost() { return RegistrationCost + Post ::TotalCost(); }
};
class InsuredRegisteredPost : public RegisteredPost
{
private:
    float AmtInsured;

public:
    InsuredRegisteredPost() { AmtInsured = 20; }
    void Read()
    {
        RegisteredPost::
            Read();
        cout << "Enter insured value of post: ";
        cin >> AmtInsured;
    }
    void Print()
    {
    RegisteredPost::
        Print();
        cout << "Insured Amount of post: " << AmtInsured << " $ " << endl;
    }
    float TotalCost() { return RegisteredPost ::TotalCost() + AmtInsured; }
};
int main()
{
    InsuredRegisteredPost envelope;
    envelope.Read();
    cout << "Post Details.." << endl;
    envelope.Print();
    return 0;
}