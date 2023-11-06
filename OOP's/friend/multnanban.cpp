#include <iostream>
using namespace std;
class temperature;
class humitity; // forward declaration
class temperature
{
    int temp;

public:
    void settemp(int t) // setter
    {
        temp = t;
    }
    friend void print(temperature, humitity); // friend function
};
class humitity
{
    int hum;

public:
    void sethum(int h)
    {
        hum = h;
    }
    friend void print(temperature, humitity);
};
void print(temperature t, humitity h)
{
    cout << "Temperature is " << t.temp << endl;
    cout << "Humitity is " << h.hum << endl;
}
int main()
{
    temperature t;
    humitity h;
    t.settemp(30);
    h.sethum(50);
    print(t, h);
    return 0;
}