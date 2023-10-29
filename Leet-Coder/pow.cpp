#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    /*int x = 2;
    int n = -2;
    cout << pow(x, n);*/
    int n = 10;
    double x = 2.000;
    long long nn = n;
    double ans = 1.0;
    if (nn < 0)
        nn = -1 * nn;
    while (nn > 0)
    {
        if (nn % 2)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
    cout << ans;
}