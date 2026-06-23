#include <iostream>
using namespace std;

class Worker
{
public:
    void work()
    {
        cout << "Working as an employee\n";
    }
};

class Freelancer
{
public:
    void work()
    {
        cout << "Working independently\n";
    }
};

class HybridWorker : public Worker, public Freelancer
{
public:
    // Override that combines both behaviors
    void work()
    {
        Worker::work();
        Freelancer::work();
    }
};

int main()
{
    HybridWorker h;

    // h.work();
    // Error : Request for "work function" is ambiguous.

    cout << "solving problem using scope resolution operator" << endl;
    h.Worker::work();
    h.Freelancer::work();

    cout << "\nsolving problem using overriding" << endl;
    h.work();

    return 0;
}
/*
Output: 

solving problem using scope resolution operator
Working as an employee
Working independently

solving problem using overriding
Working as an employee
Working independently

*/