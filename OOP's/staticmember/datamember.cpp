#include <iostream>
using namespace std;

/*
    Static Data Members:

        Static data members are class-level variables that are shared among all
        instances (objects) of the class.They are declared with the static keyword
        and must be defined separately outside the class declaration.Each instance
        of the class can access and modify the same static data member.Static data
        members are initialized only once, typically during program startup.

*/
class stavar
{
public:
    static int count; // Declaration of static data member
};
// Initialize static data member of class stavar
int stavar::count = 0;
int main()
{
    stavar obj1, obj2, obj3;
    obj1.count = 1;
    obj2.count = 2;
    obj3.count = 3;
    cout << obj1.count << endl;
    cout << obj2.count << endl;
    cout << obj3.count << endl;
    return 0;
}