#include <iostream>
using namespace std;
bool isPalindrome(int n)
{
    int rev = 0;
    int q = n, r;
    while (q != 0)
    {
        r = q % 10;
        rev = rev * 10 + r;

        q = q / 10;
        cout << "q:" << q << "r:" << rev << endl;
    }

    if (rev == n)
    {
        cout << "pali";
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    isPalindrome(n);
}