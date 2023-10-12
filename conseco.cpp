#include <iostream>
using namespace std;
int main()
{
    int nums[] = {1, 0, 1, 1, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int cnt = 0;
    int maxc = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        maxc = max(maxc, cnt);
    }
    return maxc;
}