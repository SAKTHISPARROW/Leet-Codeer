#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a = {1, 4, 5, 7};
    vector<int> b = {2, 3, 6};
    int n = a.size();
    int m = b.size();
    int l = n - 1;
    int r = 0;
    while (r < m && l >= 0)
    {
        if (a[l] > b[r])
        {
            swap(a[l], b[r]);
            l--, r++;
        }
        else
            break;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int k = 0; k < n; k++)
    {
        a.push_back(b[k]);
    }
    for (auto k : a)
    {
        cout << k << " ";
    }
}