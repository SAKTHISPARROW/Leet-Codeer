#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    set<vector<int>> set;
    vector<vector<int>> output;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            int k = j + 1;
            if (nums[i] + nums[j] + nums[k] == 0)
            {
                set.insert({nums[i], nums[j], nums[k]});
            }
        }
    }
    for (auto k : set)
    {
        output.push_back(k);
    }
    for (auto i : output)
    {
        cout << i;
    }

    return 0;
}