#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    vector<string> strs = {"flower", "flow", "flight", "apple"};
    sort(strs.begin(), strs.end());
    string f = strs[0], l = strs[strs.size() - 1];
    string ans;
    for (int i = 0; i < min(f.length(), l.length()); i++)
    {
        if (f[i] != l[i])
        {
            break;
        }
        ans += f[i];
    }
    cout << ans;
}