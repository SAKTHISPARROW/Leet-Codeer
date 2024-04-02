#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{1, 2}, {1, 3}, {1, 6}, {3, 4}, {4, 4}, {4, 5}, {5, 5}, {6, 6}, {6, 6}};
    sort(arr.begin(), arr.end());
    vector<vector<int>> intv;
    int n = arr.size();
    /*for (int i = 0; i < n; i++)
    {
        int init = arr[i][0];
        int finit = arr[i][1];
        if (!intv.empty() && intv.back()[1] >= finit)
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= finit)
            {
                finit = max(finit, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        intv.push_back({init, finit});
    }*/
    for (int i = 0; i < n; i++)
    {
        if (intv.empty() || arr[i][0] > intv.back()[1])
        {
            intv.push_back(arr[i]);
        }
        else
        {
            intv.back()[1] = max(intv.back()[1], arr[i][1]);
        }
    }
    for (auto i : intv)
    {
        for (auto k : i)
        {
            cout << k << " ";
        }
    }
}