#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void findtopo(int src, vector<int> &vis, stack<int> &s, vector<int> adj[])
    {
        vis[src] = 1;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                findtopo(it, vis, s, adj);
            }
        }
        s.push(src);
    }

public:
    vector<int> topoSort(int node, vector<int> adj[])
    {
        stack<int> s;
        vector<int> vis(node, 0);
        for (int i = 0; i < node; i++)
        {
            if (!vis[i])
            {
                findtopo(i, vis, s, adj);
            }
        }
        vector<int> res;
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

int main()
{

    int N = 6;

    vector<int> adj[5 + 1];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> res = obj.topoSort(6, adj);

    cout << "Toposort of the given graph is:" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}