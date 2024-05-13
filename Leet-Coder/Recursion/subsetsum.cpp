#include <bits/stdc++.h>
using namespace std;
void helper(int ind, int arr[], int n, vector<int> &k, int sum)
{
    if (ind == n)
    {
        k.push_back(sum);
        return;
    }
    helper(ind + 1, arr, n, k, sum + arr[ind]);
    helper(ind + 1, arr, n, k, sum);
}
vector<int> subset(int arr[], int n)
{
    vector<int> k;
    helper(0, arr, n, k, 0);
    sort(k.begin(), k.end());
    return k;
}
int main()
{
    int arr[] = {3, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = subset(arr, size);
    cout << "The sum of each subset is " << endl;
    for (int k : ans)
    {
        cout << k << " ";
    }
    cout << endl;

    return 0;
}