#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s = "PAYPALISHIRING";
    int numr = 3;
    if (numr <= 1)
        cout << s;
    vector<string> v(numr, "");
    int j = 0;
    int dir = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (j == 0 || j == numr - 1)
            dir *= -1;
        v[j] += s[i];
        if (dir == 1)
            j++;
        else
            j--;
    }
    string res;
    for (auto &k : v)
    {
        res += k;
    }
    cout << res;
}