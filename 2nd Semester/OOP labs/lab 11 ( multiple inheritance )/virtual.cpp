#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    int val;
    Base() : val(0) {}
};

class A : virtual public Base
{
};

class B : virtual public Base
{
}; // NOT virtual, virtual keyword is required to handle diamond problem.

class C : public A, public B
{
};

int main()
{
    C obj;
    obj.val = 42; // Direct access works - no ambiguity! ( because virtual keyword is added )
    cout << "Value: " << obj.val << endl;
    return 0;
}

/* Answers

Q1) How many Base sub-objects does C contain?

Ans) When a virtual keyword is not used, then C contains two sub-objects of the base class, which creates an ambiguity problem, or called as the diamond problem. 

Q2) Can you access val without ambiguity? Explain why or why not.

Ans) In the given code, the virtual keyword is not used, so we can not access val without ambiguity.

Because when we try to access val, the compiler gets confused about which val needs to be accessed, because there are two base class objects with val. 

Q3) Output:

Value: 42

*/