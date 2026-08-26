#include <iostream>
using namespace std;

class BankAccount
{
protected:
    int acc_id;
    float balance;

public:
    BankAccount(int id, float balance)
    {
        acc_id = id;
        this->balance = balance;
    }

    BankAccount()
    {
        cout << "Enter id: ";
        cin >> acc_id;

        do
        {
            cout << "Enter Balance: ";
            cin >> balance;
        } while (balance < 0);
    }

    virtual void calulate_interest() = 0;

    BankAccount &operator+=(float amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
        else
        {
            cout << "Invalid amount. Cannot add negative value." << endl;
        }
        return *this;
    }

    BankAccount &operator-=(float amount)
    {
        if (balance > amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
        return *this;
    }

    bool operator==(BankAccount &b)
    {
        return balance == b.balance;
    }
    bool operator>(BankAccount &b)
    {
        return balance > b.balance;
    }
    bool operator<(BankAccount &b)
    {
        return balance < b.balance;
    }

    // friend ostream& operator<<()
};