#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = nums.size();
    int maxsum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (maxsum < sum)
        {
            maxsum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
        /*int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            //maxsum = max(maxsum, sum);
        }*/
    }
    cout << maxsum;
}
