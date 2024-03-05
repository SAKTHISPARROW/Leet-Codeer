#include <iostream>
using namespace std;
int cntplat(int arr[], int dep[], int n)
{
    int plat = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i]))
            {
                count++;
            }
        }
        plat = max(plat, count);
    }
    return plat;
}
int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = cntplat(arr, dep, n);
    cout << res;
}