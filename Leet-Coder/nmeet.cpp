#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int e[] = {2, 4, 6, 7, 9, 9};
    vector<vector<int, int>> st;
    int n = sizeof(s) / sizeof(s[0]);
    int cnt = 0;
    int ent = 0, sta = ent + 1;
    for (int i = 0; i < n; i++)
    {
        vector<int, int> v1;
        v1.push_back(s[i]);
        v1.push_back(e[i]);
        st.push_back(v1);
    }
    for (int x : st.front())
    {
        cout << x;
    }
}