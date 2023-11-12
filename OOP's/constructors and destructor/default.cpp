/*
    Default Constructor :
        - A default constructor is a constructor that is automatically provided by
          the C++ compiler if no constructor is explicitly defined within a class.
          It initializes the object with default values or performs no initialization
          at all, depending on how it's implemented.
*/
#include <iostream>
using namespace std;
class disp
{
public:
    disp()
    { // default constructor
        cout << "Default constructor called" << endl;
    }
};

int main()
{
    disp d;
}