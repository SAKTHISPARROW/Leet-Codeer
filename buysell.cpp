#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();
    int minp = INT_MAX, pro = 0;
    for (int i = 0; i < n; i++)
    {
        minp = min(minp, prices[i]);
        pro = max(pro, prices[i] - minp);
        cout << minp << " " << pro << endl;
        ;
    }
    cout << pro;
}