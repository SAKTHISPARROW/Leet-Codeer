#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int rev = 0;
    int q = n, r;
    while (q != 0)
    {
        r = q % 10;
        rev = rev * 10 + r;
        q = q / 10;
    }
    cout << rev;
}