#include <bits/stdc++.h>
using namespace std;
struct item
{
    int v;
    int weight;
};
class knap
{
public:
    bool static comp(item a, item b)
    {
        double x = (double)a.v / (double)a.weight;
        double y = (double)b.v / (double)b.weight;
        return x > y;
    }
    int valk(item arr[], int n, int w)
    {
        sort(arr, arr + n, comp);
        int currw = 0;
        double finv = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight + currw <= w)
            {
                currw += arr[i].weight;
                finv += arr[i].v;
            }
            else
            {
                int rem = w - currw;
                finv += (arr[i].v / (double)arr[i].weight) * (double)rem;
                break;
            }
        }
        return finv;
    }
};
int main()
{
    int n = 3, weight = 50;
    item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    knap s;
    double ans = s.valk(arr, n, weight);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}