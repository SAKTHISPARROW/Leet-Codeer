#include <iostream>
using namespace std;
/*
    In multilevel inheritance, a derived class inherits from another derived class.
    This creates a chain of inheritance.

    class c inherits class B
    class B inherites class A
    C <- B <- A

    [ <- ] : inheritence

*/
class grandparent
{
public:
    int grandparentvar;
};
class parent : public grandparent
{
public:
    int parentvar;
};
class child : public parent
{
public:
    int childvar;
};
int main()
{
    child obj;
    obj.grandparentvar = 50;
    obj.parentvar = 30;
    obj.childvar = 10;

    cout << "Grandparent variable: " << obj.grandparentvar << endl;
    cout << "Parent variable: " << obj.parentvar << endl;
    cout << "Child variable: " << obj.childvar << endl;
}