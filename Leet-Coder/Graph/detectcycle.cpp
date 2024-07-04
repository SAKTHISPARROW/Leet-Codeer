#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // private:
    //  bool detect(int src, int vis[], vector<int> adj[])
    //  {
    //      vis[src] = 1;
    //      queue<pair<int, int>> q;
    //      q.push({src, -1});
    //      while (!q.empty())
    //      {
    //          int node = q.front().first;
    //          int parent = q.front().second;
    //          q.pop();
    //          for (auto i : adj[node])
    //          {
    //              if (!vis[i])
    //              {
    //                  vis[i] = 1;
    //                  q.push({i, node});
    //              }
    //              else if (parent != i)
    //              {
    //                  return true;
    //              }
    //          }
    //      }
    //      return false;
    //  }
private:
    bool detect(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                if (detect(i, node, vis, adj))
                    return true;
            }
            else if (parent != i)
                return true;
        }
        return false;
    }

public:
    bool isCycle(int v, vector<int> adj[])
    {
        int vis[v] = {0};
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                /// if (detect(0, vis, adj))            //bfs
                if (detect(0, -1, vis, adj)) // dfs
                    return true;
            }
        }
        return false;
    }
};
int main()
{

    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "Cycle Found\n";
    else
        cout << "Cycle Not Found\n";
    return 0;
}