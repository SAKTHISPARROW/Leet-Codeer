#include <iostream>
#include <limits.h>
using namespace std;
int seclar(int arr[], int n)
{
    int l = arr[0], sl = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (sl < arr[i] && l > arr[i])
        {
            sl = arr[i];
        }
        if (l < arr[i])
        {
            sl = l;
            l = arr[i];
        }
        // cout << ss << " " << s << endl;
    }

    return sl;
}
int main()
{
    int arr[] = {70, 40, 30, 20, 15, 10, 5, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << seclar(arr, n);
}
