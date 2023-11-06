/*
    Constructor :
        - Constructor is a function which name is same as class name and
          having no return type.

        - Constructor is a special method that is invoked automatically
          at the time of object creation.

        - It is used to initialize the data members of new objects generally.

        - Constructors are used to initialize the data members of the object and perform any necessary setup.


    Constuctor is of three type.
        1.Default or Non-parameterized
        2.Parameterized
        3.Copy


    Default Constructor :
        - Default Constructors don’t have input argument however.

        - If we do not specify a constructor, C++ compiler generates a default
          constructor for object (expects no parameters and has an empty body).

        - A default constructor is a constructor with no parameters.
          It is automatically called when an object is created if no other constructor is specified.

    Parameterized Constructor :
        - A parameterized constructor accepts one or more parameters to initialize
          the object with specific values.

    Copy Constructor :
        - A copy constructor creates a new object by copying the values of another
          object of the same class. It is used when objects are passed by value or when objects are created as
*/
#include <iostream>
using namespace std;
class dog
{
private:
    string name;

public:
    dog()
    { // default constructor
        name = "";
    }
    dog(string s)
    { // parameterized constructor
        name = s;
    }
    dog(dog &d)
    {
        name = d.name; // copy constructor
    }
    void run()
    {
        cout << name << " is running" << endl;
    }
};
int main()
{
    dog d1("Tommy");
    dog d2(d1);
    dog d3;
    d1.run();
    d2.run();
    d3.run();
}