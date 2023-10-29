#include <iostream>
using namespace std;
class shape
{
public:
    virtual double calca()
    {
        return 0.0;
    }
};
class circle : public shape
{
private:
    double radius;

public:
    circle(double r) : radius(r) {}
    double calca() override
    {
        return 3.14159 * radius * radius;
    }
};
class rectan : public shape
{
private:
    double length;
    double width;

public:
    rectan(double l, double w) : length(l), width(w) {}
    double calca() override
    {
        return length * width;
    }
};
int main()
{
    shape *Circle = new circle(6.0);
    cout << "Area of circle: " << Circle->calca() << endl;
    shape *Rectan = new rectan(4, 5);
    cout << "Area of rectangle: " << Rectan->calca() << endl;
}