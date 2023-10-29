#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> s = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    sort(s.begin(), s.end());
    int cnt = 1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        // cout << s[i];
        if (s[i] + 1 == s[i + 1] || s[i] == s[i + 1])
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    cout << cnt;
}