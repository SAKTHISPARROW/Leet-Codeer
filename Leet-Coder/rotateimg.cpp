#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> rotmat = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int n = mat.size();
    /*int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //cout << i << j << endl;
            rotmat[i][j] = mat[m - j - 1][i];
        }
    }

    for (auto x : rotmat)
    {
        for (auto y : x)
        {
            cout << y;
        }
    }*/
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << j << endl;
            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int k = 0; k < n; k++)
    {
        reverse(mat[k].begin(), mat[k].end());
    }
    for (auto x : mat)
    {
        for (auto y : x)
        {
            cout << y;
        }
    }
}