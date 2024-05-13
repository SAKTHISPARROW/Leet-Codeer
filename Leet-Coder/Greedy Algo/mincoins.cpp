#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v = 65;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    vector<int> k;
    for (int i = n - 1; i >= 0; i--)
    {
        while (v >= coins[i])
        {
            v -= coins[i];
            k.push_back(coins[i]);
        }
    }
    cout << "The minimum number of coins is " << k.size() << endl;
    cout << "The coins are " << endl;
    for (int i : k)
    {
        cout << i << " ";
    }
    return 0;
}