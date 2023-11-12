/*
    Copy Constructor :
        - A copy constructor is a special constructor in C++ that is used to
          create a new object as a copy of an existing object of the same class.
          It is often used when objects are passed by value, returned by value
          from a function, or when you explicitly create a new object as a copy
          of an existing one.
*/
#include <iostream>
using namespace std;
class person
{
private:
    string name;
    int age;

public:
    person(string s, int n)
    {
        name = s;
        age = n;
    }
    person(person &p)
    {
        name = p.name; // copy constructor
        age = p.age;
    }
    void intro()
    {
        cout << "My name is " << name << " and I am " << age << " years old." << endl;
    }
};
int main()
{
    person john("John", 25); // object of derived class
    john.intro();
    person john2 = john; // copy constructor
    john2.intro();
}