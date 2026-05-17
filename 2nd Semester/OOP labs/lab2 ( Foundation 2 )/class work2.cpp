#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string name;
    string pass;
    double balance;

public:
    // prototypes for constructors.
    BankAccount();                       // for default constructor
    BankAccount(string, string, double); // for parametrized constructor
    BankAccount(BankAccount &obj);       // for copy constructor

    // Getter(s)
    double get_balance()
    {
        return balance;
    }

    // prototypes for behaviors.
    void deposit(void);
    void withdraw(void);
};

// Definition of constructors.
BankAccount ::BankAccount() // for default constructor
{
    name = "ABC";
    pass = "123";
    balance = 0;
}

BankAccount ::BankAccount(string Name, string password, double Balance) // for parameterized constructor
{
    name = Name;
    pass = password;
    balance = Balance;
}

BankAccount ::BankAccount(BankAccount &obj) // for copy constructor
{
    name = obj.name;
    pass = obj.pass;
    balance = obj.balance;
}

// Definition of behaviors.
void BankAccount ::deposit(void)
{
    double dep;
    string password;
    cout << "Enter password: ";
    cin >> password;
    if (password == pass)
    {
        cout << name << " is successfully logedin" << endl;
        cout << name << ", kindly enter amout you want to deposit: ";
        cin >> dep;
        balance += dep;
        cout << "You have successfully deposited " << dep << " amount in your account" << endl;
    }
    else
    {
        cout << "The input password is incorrect" << endl;
    }
}

void BankAccount ::withdraw(void)
{
    double Wdraw;
    string password;
    cout << "Enter password: ";
    cin >> password;
    if (password == pass)
    {
        cout << name << " is successfully logedin" << endl;
        cout << name << ", kindly enter amout you want to withdraw: ";
        cin >> Wdraw;
        if (Wdraw > balance)
        {
            cout << name << ", you dont have much balanced in your account to withdraw " << Wdraw << "amount" << endl;
        }
        else
        {
            balance -= Wdraw;
            cout << "You have successfully withdraw " << Wdraw << " amount from your account" << endl;
        }
    }
    else
    {
        cout << "The input password is incorrect" << endl;
    }
}
void printMenu(void);
int main()
{
    BankAccount obj; // calls default constructor

    while (true)
    {
        printMenu();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string name, password;
            double balance;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter initial balance: ";
            cin >> balance;
            obj = BankAccount(name, password, balance); // A temp obj is created with parametrized constructor and then it is being retured to obj.
            break;
        } // {} Added because balance is also decalred in case 4. So by this {} balance of case 1 is local and case 4 cant see it.
        case 2:
            obj.deposit();
            break;
        case 3:
            obj.withdraw();
            break;
        case 4:
            double balance;
            balance = obj.get_balance();
            cout << "Amount: " << balance << endl;
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
void printMenu(void)
{
    cout << "1 - Create an account" << endl;
    cout << "2 - Deposit amount" << endl;
    cout << "3 - Withdraw amount" << endl;
    cout << "4 - Check balance" << endl;
    cout << "5 - Exit" << endl;
    cout << "Choose your choice: " << endl;
}