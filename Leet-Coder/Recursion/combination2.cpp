#include <bits/stdc++.h>
using namespace std;
void setsum(vector<vector<int>> &ans, vector<int> s, int arr[], int n, int ind, int t)
{
    if (t == 0)
    {
        ans.push_back(s);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > t)
            break;
        s.push_back(arr[i]);
        setsum(ans, s, arr, n, i + 1, t - arr[i]);
        s.pop_back();
    }
}
void comp(int arr[], int n, int t)
{
    sort(arr, arr + n);
    vector<vector<int>> ans;
    vector<int> s;
    setsum(ans, s, arr, n, 0, t);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int t = 8;
    comp(arr, size, t);
}