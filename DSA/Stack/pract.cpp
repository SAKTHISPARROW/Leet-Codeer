#include <bits/stdc++.h>
using namespace std;
void dailyTemperatures(vector<int> &T)
{
    int n = T.size();
    vector<int> daysOfWait(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && T[s.top()] < T[i])
        {
            daysOfWait[s.top()] = i - s.top();
            cout << s.top() << endl;
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << daysOfWait[i] << " ";
    }
}
int main()
{
    vector<int> arr{67, 79, 70, 81, 60, 70, 82};
    dailyTemperatures(arr);
    return 0;
}