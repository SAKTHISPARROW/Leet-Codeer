#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    // Function to add an edge to the graph
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming it's an undirected graph
    }

    // Function to perform BFS and find the shortest path
    vector<int> bfs(int src, int dest)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int node = q.front();
            cout << node << endl;
            q.pop();

            // Stop BFS when we reach the destination
            if (node == dest)
                break;

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = node;
                    // cout << node;
                }
            }
        }
        // Reconstruct the path from src to dest
        vector<int> path;
        for (int at = dest; at != -1; at = parent[at])
        {
            // cout << at;
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        // If src is not connected to dest, return an empty path
        if (path[0] != src)
            path.clear();

        return path;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 4);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    int src = 0;
    int dest = 4;

    vector<int> path = g.bfs(src, dest);

    if (!path.empty())
    {
        cout << "Shortest path from " << src << " to " << dest << " is: ";
        for (int node : path)
        {
            cout << node << " ";
        }
    }
    else
    {
        cout << "No path exists between " << src << " and " << dest << ".";
    }

    return 0;
}
