#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Number of rows to print" << endl;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        for (int j = n; j < n - i; j--)
        {
            cout << " ";
        }
        for (int k = 1; k < 2 * i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
