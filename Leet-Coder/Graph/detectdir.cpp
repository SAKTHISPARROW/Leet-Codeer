#include <bits/stdc++.h>
using namespace std;
// class Solution                                       //BFS's Kahn's
// {
// public:
//     bool isCyclic(int V, vector<int> adj[])
//     {
//         int degree[V] = {0};
//         for (int i = 0; i < V; i++)
//         {
//             for (auto j : adj[i])
//             {
//                 degree[j]++;
//             }
//         }
//         queue<int> q;
//         for (int i = 0; i < V; i++)
//         {
//             if (degree[i] == 0)
//             {
//                 q.push(i);
//             }
//         }
//         int cnt = 0;
//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();
//             cnt++;
//             for (auto it : adj[node])
//             {
//                 degree[it]--;
//                 if (degree[it] == 0)
//                 {
//                     q.push(it);
//                 }
//             }
//         }
//         if (cnt == V)
//         {
//             return false;
//         }
//         return true;
//     }
// };
class Solution
{ // DFS
private:
    bool detect(int src, int vis[], int dfsvis[], vector<int> adj[])
    {
        vis[src] = 1;
        dfsvis[src] = 1;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                if (detect(it, vis, dfsvis, adj))
                    return true;
            }
            else if (dfsvis[it])
            {
                return true;
            }
        }
        dfsvis[src] = 0;
        return false;
    }

public:
    bool isCyclic(int v, vector<int> adj[])
    {
        int vis[v];
        int dfsvis[v];
        memset(vis, 0, sizeof vis);
        memset(dfsvis, 0, sizeof dfsvis);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                /// if (detect(0, vis, adj))            //bfs
                if (detect(i, vis, dfsvis, adj)) // dfs
                    return true;
            }
        }
        return false;
    }
};
int main()
{

    // V = 6;
    vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
    int V = 6;
    Solution obj;
    bool ans = obj.isCyclic(V, adj);
    if (ans)
        cout << "Cycle Found\n";
    else
        cout << "Cycle Not Found\n";
    cout << endl;
    return 0;
}