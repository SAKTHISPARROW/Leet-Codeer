#include <iostream>
using namespace std;
/*
    Static Member Functions:
        Static member functions are class-level functions that do not operate on
        specific instances of the class. They are associated with the class itself
        rather than objects.They are declared with the static keyword and can be
        called using the class name, without the need to create instances of the
        class.Static member functions can only access static data members and other
        static member functions of the class since they don't have access to instance
        specific data.
*/
class memfun
{
public:
    static int add(int a, int b)
    {
        return a + b;
    }
};
int main()
{
    int res = memfun::add(10, 20);
    cout << res << endl;
    return 0;
}