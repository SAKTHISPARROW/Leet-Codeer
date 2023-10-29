#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int l = 0, h = l + 1;
    int sum = 0;
    while (l != size - 1)
    {
        // cout << l << h << endl;
        if (arr[l] <= arr[h] && l + 1 != h && arr[l] != 0)
        {
            for (int i = l + 1; i < h; i++)
            {
                sum += arr[l] - arr[i];
            }
            l = h;
            h = l + 1;
        }
        else if (h != size - 1)
        {
            h++;
        }
        else
        {
            l++;
            h = l + 1;
        }
    }
    cout << "SUM:" << sum;
}