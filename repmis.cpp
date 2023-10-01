#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 2};
    int n = 0;
    int i = arr[0];
    while (n < arr.size() - 1)
    // for (int i = arr[0]; i < n + arr[n - 1]; i++)
    {
        if (i + 1 != arr[n + 1])
        {
            cout << arr[n + 1] << " " << arr[n] + 1 << endl;
            n++;
            i = arr[n];
            // cout << n << " " << i << endl;
        }
        else
        {
            n++;
            i = arr[n];
        }
    }
}