#include <iostream>
using namespace std;
/*
    Virtual Destructor :
        If we create pointer of base class which is pointing to the
        derived class then we only base will be destroyed and derived
        class will not be destroyed.

        For destroying both base and derived class we need to create virtual
        destructor by using virtual keyword in front of destructor of base class

        Virtual function can't be overloaded.

*/
class base
{
    // destructor
    /*
        in this case output will be ->

            Base class destroyed
    */

    // ~Base(){
    // 	cout << "Base class destroyed" << endl;
    // }

    // After using virtual keyword
    /*
        output will be ->

            derived class destroyed
            Base class destroyed

    */
public:
    virtual ~base()
    {
        cout << "Base class destructor" << endl;
    }
};
class derived : public base
{
public:
    ~derived()
    {
        cout << "Derived class destructor" << endl;
    }
};
int main()
{
    base *b = new derived(); // Base class pointer pointing to derived class object
    delete b;
    return 0;
}