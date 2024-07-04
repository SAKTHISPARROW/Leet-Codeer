#include <iostream>
#include <vector>
using namespace std;
class Graph
{
    int v;
    int e;
    int **adj;

public:
    Graph(int v, int e);
    void addedge(int s, int e);
    void bfs(int s);
    void findpath(int s, int e);
};
Graph::Graph(int v, int e)
{
    this->v = v;
    this->e = e;
    adj = new int *[v];
    for (int i = 0; i < v; i++)
    {
        adj[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            adj[i][j] = 0;
        }
    }
}
void Graph::addedge(int s, int e)
{
    adj[s][e] = 1;
    adj[e][s] = 1;
}
void Graph::bfs(int s)
{
    vector<bool> visited(v, false);
    vector<int> q;
    q.push_back(s);
    visited[s] = true;
    int vis;
    while (!q.empty())
    {
        vis = q[0];
        cout << vis << " -> ";
        q.erase(q.begin());
        for (int i = 0; i < v; i++)
        {
            if (adj[vis][i] == 1 && (!visited[i]))
            {
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            cout << i << " -> ";
        }
    }
}
void Graph::findpath(int s, int e)
{
    vector<bool> visited(v, false);
    vector<int> q;
    q.push_back(s);
    visited[s] = true;
    int vis, flag = 0;
    while (!q.empty())
    {
        vis = q[0];
        if (vis == e)
        {
            flag = 1;
        }
        cout << vis << " -> ";
        q.erase(q.begin());
        for (int i = 0; i < v; i++)
        {
            if (adj[vis][i] == 1 && (!visited[i]))
            {
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
    if (flag == 1)
    {
        cout << "Path existed";
    }
    else
    {
        cout << "Path not existed";
    }
}
int main()
{
    int v = 10, e = 10;
    Graph g(v, e);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(2, 4);
    g.addedge(3, 4);
    g.addedge(2, 6);
    g.addedge(6, 7);
    g.addedge(3, 5);
    g.addedge(5, 4);
    g.addedge(8, 9);
    g.findpath(0, 9);
    // g.bfs(0);
    return 0;
}