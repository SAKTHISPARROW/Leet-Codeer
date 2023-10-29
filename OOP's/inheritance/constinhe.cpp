#include <iostream>
using namespace std;
class base
{
public:
    base(int x)
    {
        this->x = x;
        cout << "base constructor with x= " << x << endl;
    }
    void show()
    {
        cout << "x=" << x << endl;
    }

private:
    int x;
};
/*
    Derived class is inheriting base class publicly tha means Public inheritance
    is a way of expressing an "is-a" relationship between classes. It means that
    the derived class Derived is a type of the base class Base and inherits
    its public and protected properties. Public members of Base remain public in
    Derived,allowing them to be used within Derived and by external code.
*/
class derived : public base
{
public:
    // Constructor of the Derived class
    derived(int x, int y) : base(x)
    {
        this->y = y;
        cout << "Derived class constructor called with y = " << y << endl;
    }

    void showY()
    {
        cout << "Value of y in Derived class: " << y << endl;
    }

private:
    int y;
};
int main()
{
    derived d(10, 20);
    d.show();
    d.showY();
    return 0;
}