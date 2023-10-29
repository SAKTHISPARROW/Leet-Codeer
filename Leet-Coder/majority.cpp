#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {2, 2, 2, 2, 1, 1, 1};
    int el;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if (el == nums[i])
            cnt++;
        else
            cnt--;
    }
    int maj = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (el == nums[j])
        {
            maj++;
        }
    }
    if (maj >= nums.size() / 2)
    {
        cout << el;
    }
    return -1;
}