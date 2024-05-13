#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool issafe(int row, int col, vector<string> &board, int n)
{
    int drow = row;
    int dcol = col;

    // Check diagonal up-left
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row--;
    }

    col = dcol;
    row = drow;

    // Check left
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    col = dcol;
    row = drow;

    // Check diagonal down-left
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row++;
    }

    return true;
}

void solve(int col, int n, vector<vector<string>> &ans, vector<string> &board)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (issafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, n, ans, board);
            board[row][col] = '-';
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '-'));

    solve(0, n, ans, board);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
