#include <iostream>
#include <unordered_set>
using namespace std;
/*int main()
{
    string s = "abcabcbb";
    int maxe = 0;
    for (int i = 0; i < s.length(); i++)
    {
        unordered_set<int> set;
        for (int j = i; j < s.length(); j++)
        {
            if (set.find(s[j]) != set.end())
            {
                maxe = max(maxe, j - i);
                break;
            }
            set.insert(s[j]);
        }
    }
    cout << maxe;
}*/
int main()
{
    string s = "abcabcbb";
    int maxe = 0;
    int l = 0;
    unordered_set<int> st;
    for (int r = 0; r < s.length(); r++)
    {
        if (st.find(s[r]) != st.end())
        {
            while (l < r && st.find(s[r]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }
        }
        st.insert(s[r]);
        maxe = max(maxe, r - l + 1);
    }
    cout << maxe;
}