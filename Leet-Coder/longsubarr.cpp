#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> s = {1, 0, -1, 1};
    int n = s.size();
    int sum, cn;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum = s[i] + s[j];
            if (sum == 0)
            {
                cout << i << j << endl;
                cn++;
            }
        }
    }
    cout << cn;
}