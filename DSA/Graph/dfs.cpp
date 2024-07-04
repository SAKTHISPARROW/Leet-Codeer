#include <iostream>
using namespace std;
class Graph
{
    int v;
    int e;
    int **adj;

public:
    Graph(int v, int e);
    void addedge(int s, int e);
    void dfs(int s, bool *visited);
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
void Graph::dfs(int s, bool *visited)
{
    cout << s << " -> ";
    visited[s] = true;
    for (int i = 0; i < v; i++)
    {
        if (adj[s][i] == 1 && (!visited[i]))
        {
            dfs(i, visited);
        }
    }
}
int main()
{
    int v = 10, e = 9;
    Graph g(v, e);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(2, 4);
    g.addedge(2, 6);
    g.addedge(6, 7);
    g.addedge(3, 5);
    g.addedge(5, 4);
    g.addedge(8, 9);
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    g.dfs(0, visited);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            cout << i << " -> ";
        }
    }
    return 0;
}