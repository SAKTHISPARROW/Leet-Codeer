#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int arr[] = {10, 30, 10, 20, 10, 20, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> ct;
    for (int i = 0; i < n; i++)
    {
        ct[arr[i]]++;
    }
    for (auto it : ct)
    {
        cout << it.first << " occurs " << it.second << " times\n";
    }
}