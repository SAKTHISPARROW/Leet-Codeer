#include <bits/stdc++.h>
using namespace std;
#define edge pair<int, int>
class Graph
{
    vector<pair<int, edge>> G; // for graph creation
    vector<pair<int, edge>> T; // for MST
    int *parent;
    int v; // these are number of vertices in graph
public:
    Graph(int v);
    void addweightedG(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};
Graph::Graph(int v)
{
    parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    G.clear();
    T.clear();
}
void Graph::union_set(int u, int v)
{
    parent[u] = parent[v];
}
void Graph::addweightedG(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i)
{
    if (i == parent[i])
    {
        return i;
    }
    else
    {
        return find_set(parent[i]);
    }
}
void Graph::kruskal()
{
    int urep, vrep, i;
    sort(G.begin(), G.end());
    for (int i = 0; i < G.size(); i++)
    {
        urep = find_set(G[i].second.first);
        vrep = find_set(G[i].second.second);
        if (urep != vrep)
        {
            T.push_back(G[i]);
            union_set(urep, vrep);
        }
    }
}
void Graph::print()
{
    int sum = 0;
    cout << " Edge :" << " Weight " << endl;
    for (int i = 0; i < T.size(); i++)
    {
        cout << T[i].second.first << "   " << T[i].second.second << "   " << T[i].first << endl;
        sum += T[i].first;
    }
    cout << " The Min Distance is :" << sum;
}
int main()
{
    Graph g(6);
    g.addweightedG(0, 1, 1);
    g.addweightedG(0, 2, 3);
    g.addweightedG(1, 2, 4);
    g.addweightedG(1, 3, 11);
    g.addweightedG(1, 5, 10);
    g.addweightedG(2, 4, 12);
    g.addweightedG(2, 5, 5);
    g.addweightedG(4, 5, 2);
    g.addweightedG(3, 5, 6);
    g.kruskal();
    g.print();
    // vector<pair<int, int>> vect;
    // int arr[] = {10, 20, 5, 40};
    // int arr1[] = {30, 60, 20, 50};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < n; i++)
    // {
    //     vect.push_back(make_pair(arr[i], arr1[i]));
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << vect[i].first << " " << vect[i].second << endl;
    // }
}