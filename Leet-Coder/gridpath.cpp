#include <iostream>
#include <vector>
using namespace std;
int countpath(int n, int m, int i, int j, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = countpath(n, m, i + 1, j, dp) + countpath(n, m, i, j + 1, dp);
    }
}
int main()
{
    int n, m;
    // int N, r;
    // int res = 1;
    cin >> n >> m;
    /*N = n + m - 2;
    r = m - 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }
    cout << res << endl;*/
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    int num = countpath(n, m, 0, 0, dp);
    if (m == 1 && n == 1)
        cout << num;
    cout << dp[1][1];
}