#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> romens = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (romens[s[i]] < romens[s[i + 1]])
        {
            ans -= romens[s[i]];
            cout << romens[s[i]] << endl;
        }
        else
        {
            ans += romens[s[i]];
        }
    }
    cout << ans;
}