#include <iostream>
using namespace std;
class base1
{
public:
    int x;
};
class base2
{
public:
    int y;
};
class derived : public base1, public base2
{
public:
    void display()
    {
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
    }
};
int main()
{
    derived d;
    d.x = 10;
    d.y = 20;
    d.display();
    return 0;
}