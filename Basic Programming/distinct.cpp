#include <iostream>
#include <set>
using namespace std;
int main()
{
    int arr[] = {10, 30, 10, 20, 10, 20, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    for (auto it : s)
    {
        cout << it << " ";
    }
}