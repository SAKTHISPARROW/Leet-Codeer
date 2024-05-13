#include <bits/stdc++.h>
using namespace std;
/*void fun(vector<int> nums, set<vector<int>> &res, vector<int> ds, int ind)
{
    if (ind == nums.size())
    {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
    }
    ds.push_back(nums[ind]);
    fun(nums, res, ds, ind + 1);
    ds.pop_back();
    fun(nums, res, ds, ind + 1);
}*/
void fun(vector<int> nums, vector<int> &ds, vector<vector<int>> &ans, int ind)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        fun(nums, ds, ans, i + 1);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> nums)
{
    vector<vector<int>> ans;
    // set<vector<int>> res;
    vector<int> ds;
    // fun(nums, res, ds, 0);
    sort(nums.begin(), nums.end());
    fun(nums, ds, ans, 0);
    return ans;
}
void printAns(vector<vector<int>> &ans)
{
    cout << "The unique subsets are " << endl;
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " ]";
}
int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    printAns(ans);
    return 0;
}