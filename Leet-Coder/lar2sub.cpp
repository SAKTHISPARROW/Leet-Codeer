#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n = 8;
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else if (sumIndexMap.find(sum) != sumIndexMap.end())
        {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        }
        else
        {
            sumIndexMap[sum] = i;
        }
    }
    for (int x = 0; x < sumIndexMap.size(); x++)
    {
        cout << sumIndexMap[x] << endl;
    }
    cout << maxLen;
    return 0;
}