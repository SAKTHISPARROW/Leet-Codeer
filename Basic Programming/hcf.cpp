#include <iostream>
using namespace std;
int hcf(int n, int m)
{
    return (m == 0) ? n : hcf(m, n % m);
}
int main()
{
    int n, m;
    cout << "Enter num:" << endl;
    cin >> n;
    cin >> m;
    cout << "Hcf of number is:" << hcf(n, m) << endl;
}