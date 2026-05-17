#include <iostream>
using namespace std;

class Product
{
private:
    string name_;
    int product_id_;

public:
    // constructors
    Product()
    {
        name_ = "ABC";
        product_id_ = 0;
    }
    Product(string n, int id)
    {
        name_ = n;
        product_id_ = id;
    }
    // getters
    string get_name() { return name_; }
    int get_productID() { return product_id_; }
    // method(s)
    virtual void Display()
    {
        cout << "Name: " << name_ << endl;
        cout << "Product ID: " << product_id_ << endl;
    }
};
class Utility_Items : public Product
{
private:
    int discount;

public:
    // constructors
    Utility_Items()
    {
        discount = 0;
    }
    Utility_Items(string n, int id, int discnt) : Product(n, id), discount(discnt) {}
    // methods(s)
    void Display() override
    {
        Product ::Display();
        cout << get_name() << " is " << discount << " % discounted" << endl;
    }
};
class Food_Items : public Product
{
private:
    int date_of_exp;

public:
    // constructors
    Food_Items()
    {
        date_of_exp = 1;
    }
    Food_Items(string n, int id, int years) : Product(n, id), date_of_exp(years) {}
    // methods(s)
    void Display() override
    {
        Product ::Display();
        cout << get_name() << " will remain fresh for " << date_of_exp << " years." << endl;
    }
};
int main()
{
    Product toy("car", 1);
    toy.Display();

    Utility_Items Brush("Hair Brush", 2, 20);
    Brush.Display();

    Food_Items Dates("Irani Dates", 3, 2);
    Dates.Display();
}