#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool palind(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void part(string s, vector<vector<string>> &ans, vector<string> k, int ind)
{
    if (ind == s.size())
    {
        ans.push_back(k);
        return;
    }
    for (int i = ind; i < s.length(); i++)
    {
        if (palind(s, ind, i))
        {
            k.push_back(s.substr(ind, i - ind + 1));
            part(s, ans, k, i + 1);
            k.pop_back();
        }
    }
}

int main()
{
    string s = "aabb";
    vector<vector<string>> ans;
    vector<string> k;
    part(s, ans, k, 0);
    for (auto i : ans)
    {
        cout << "[ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}
