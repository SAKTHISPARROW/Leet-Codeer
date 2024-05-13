#include <iostream>
using namespace std;
int main()
{
    const int a = 10;
    const int *b = &a;
    int *c = const_cast<int *>(b);
    *c = 20;
    cout << a << endl;
    cout << *c << endl;
    return 0;
}