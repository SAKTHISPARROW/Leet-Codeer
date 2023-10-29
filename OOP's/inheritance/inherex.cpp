#include <iostream>
using namespace std;
class rectan
{
public:
    int length, breadth;
    void show()
    {
        cout << "length=" << length << endl;
        cout << "breadth=" << breadth << endl;
    }
    void area()
    {
        cout << "area=" << length * breadth << endl;
    }
};
class cube : public rectan
{
public:
    int height;
    void show()
    {
        cout << "length=" << length << endl;
        cout << "breadth=" << breadth << endl;
        cout << "height=" << height << endl;
    }
    void area()
    {
        cout << "area=" << length * breadth * height << endl;
    }
};
int main()
{
    rectan r;
    r.length = 10;
    r.breadth = 20;
    r.show();
    r.area();
    cube c;
    c.length = 10;
    c.breadth = 20;
    c.height = 30;
    c.show();
    c.area();
    return 0;
}