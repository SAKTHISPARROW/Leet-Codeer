#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> zeromat(vector<vector<int>> &matrix, int n, int m)
{
    int row[n] = {0};
    int col[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int x = 0; x < m; x++)
        {
            if (row[k] || col[x])
            {
                matrix[k][x] = 0;
            }
        }
    }
    return matrix;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeromat(matrix, n, m);
    for (auto y : ans)
    {
        for (auto i : y)
        {
            cout << i << "";
        }
        cout << "\n";
    }
}