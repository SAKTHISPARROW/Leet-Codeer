#include <iostream>
#include <map>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int xr = 0;
    map<int, int> mpp;

    mpp[xr]++;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    cout << cnt;
}