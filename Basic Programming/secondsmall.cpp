#include <iostream>
#include <limits.h>
using namespace std;
int secSmallest(int arr[], int n)
{
    int s = arr[0], ss = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (ss > arr[i] && s < arr[i])
        {
            ss = arr[i];
        }
        if (s > arr[i])
        {
            ss = s;
            s = arr[i];
        }
        // cout << ss << " " << s << endl;
    }

    return ss;
}
int main()
{
    int arr[] = {70, 40, 30, 20, 15, 10, 5, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << secSmallest(arr, n);
}
