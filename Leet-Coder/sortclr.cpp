#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> col = {2, 0, 2, 1, 1, 0};
    int n = col.size();
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (col[i] == 0)
            cnt0++;
        else if (col[i] == 1)
            cnt1++;
        else
            cnt2;
    }
    for (int i = 0; i < cnt0; i++)
        col[i] = 0; // replacing 0's

    for (int i = cnt0; i < cnt0 + cnt1; i++)
        col[i] = 1; // replacing 1's

    for (int i = cnt0 + cnt1; i < n; i++)
        col[i] = 2; // replacing 2's
    for (auto k : col)
    {
        cout << k << " ";
    }
}