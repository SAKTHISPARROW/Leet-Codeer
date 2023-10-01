#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
// bruteforce
/*int main(){
    int tar=18;
    int arr[10]={2,7,11,15};
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(arr[i]+arr[j]==tar)    printf("\n%d,%d",i,j);
            else    printf("\ntarget not found");
            break;
        }
    }
    return 0;
}*/
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) == mp.end())
            mp[nums[i]] = i;
        else
            printf("\n%d,%d", mp[target - nums[i]], i);
        printf("\n%d", mp[nums[i]]);
    }

    return {-1, -1};
}
int main()
{
    vector<int> nums = {3, 3};
    int target = 6;
    twoSum(nums, target);
}