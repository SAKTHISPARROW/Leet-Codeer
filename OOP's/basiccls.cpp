#include <iostream>
using namespace std;
/*
    Class :
        - A class is a blueprint or template for creating objects (instances).
        - It defines the structure and behavior of objects that will be created based on it.
        - A class encapsulates data (attributes) and functions (methods) that operate on that data into a single unit.
        - A class is a user-defined data type. It allows you to define a new data type based on the structure and behavior you define within the class.

*/
class mycls
{
private:
    // data members
    string name;
    int age;

public:
    mycls(string n, int a)
    { // constructor
        name = n;
        age = a;
    }
    void intro()
    {
        cout << "My name is " << name << " and I am " << age << " years old." << endl;
    }

protected:
    string famname;
    int famage;
};
/*class myclsc : public mycls // inheritance
{
public:
    myclsc(string s, int n)
    { // constructor of protected class
        famname = s;
        famage = n;
    }
    void introfam()
    {
        cout << "My family name is " << famname << " and I am " << famage << " years old." << endl;
    }
};*/
int main()
{
    mycls john("John", 25); // object of derived class
    john.intro();
    // myclsc johnfam("John", 3); // object of derived class
    // johnfam.introfam();
}