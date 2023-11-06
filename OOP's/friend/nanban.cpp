#include <iostream>
using namespace std;
/*

    Friend Class :
        A friend class can access private and protected members of other classes
        in which it is declared as a friend. It is sometimes useful to allow a
        particular class to access private and protected members of other classes.
        For example, a LinkedList class may be allowed to access private members of
        Node.We can declare a friend class in C++ by using the friend keyword.

    We can declare friend class or function anywhere in the base class body whether
    its private, protected or public block. It works all the same.
*/

class samp
{
    int a;

protected:
    int b;

public:
    samp()
    {
        a = 10;
        b = 20;
    }
    friend class samp1;
};
/*
    Here, class FriendClass is declared as a friend inside class FriendClassImpl.
    Therefore,FriendClass is a friend of class FriendClassImpl. Class FriendClass
    can access the private members of class FriendClassImpl.
*/
class samp1
{
public:
    void disp(samp &s)
    {
        cout << "private variable :" << s.a << endl;
        cout << "protected variable :" << s.b << endl;
    }
};
int main()
{
    samp s;
    samp1 s1;
    s1.disp(s);
    return 0;
}