#include <iostream>
using namespace std;
/*


    Friend Function

        Like a friend class, a friend function can be granted special access to
        private and protected members of a class in C++. They are the non-member
        functions that can access and manipulate the private and protected members
        of the class for they are declared as friends.

        A friend function can be:

            a) A global function
                We can declare any global function as a friend function.
                The following example demonstrates how to declare a global
                function as a friend function in C++:
            b) A member function of another class

*/
class person
{
    string name;
    int age;

protected:
    string addr;

public:
    person(const string &s, int a, string &b) // constructor
    {
        name = s;
        age = a;
        addr = b;
    }
    friend void print(person &p); // friend function
};
void print(person &p)
{
    cout << p.name << endl;
    cout << p.age << endl;
    cout << p.addr << endl;
}
int main()
{
    string s = "John";
    string b = "USA";
    person p(s, 25, b);
    print(p);
    return 0;
}