#include <bits/stdc++.h>
using namespace std;
void permute(int arr[], vector<vector<int>> &ans, vector<int> &ds, int freq[])
{
    if (ds.size() == 3)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (!freq[i])
        {
            ds.push_back(arr[i]);
            freq[i] = 1;
            permute(arr, ans, ds, freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[] = {0, 0, 0};
    permute(arr, ans, ds, freq);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}