#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {3, 1, 3, 4, 2};
    sort(arr, arr + 5);
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cout << arr[i];
        }
    }
}