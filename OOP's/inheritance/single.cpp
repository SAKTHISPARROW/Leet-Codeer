#include <iostream>
using namespace std;
class base
{
private:
    int x;

public:
    void setx(int x)
    {
        this->x = x;
    }
    int getx()
    {
        return x;
    }
};
class derived : public base
{
public:
    void show()
    {
        cout << "x=" << getx() << endl;
    }
};
int main()
{
    derived d;
    d.setx(10);
    d.show();
    return 0;
}