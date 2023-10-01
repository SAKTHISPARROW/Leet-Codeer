#include <iostream>
#include <vector>
using namespace std;
vector<int> gen(int row)
{
    long long a = 1;
    vector<int> ans;
    ans.push_back(1);
    for (int col = 1; col < row; col++)
    {
        a = a * (row - col);
        a = a / (col);
        ans.push_back(a);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> pascal;
    for (int i = 1; i <= n; i++)
    {
        pascal.push_back(gen(i));
    }
    for (auto i : pascal)
    {
        for (auto j : i)
        {
            cout << j << endl;
        }
    }
}