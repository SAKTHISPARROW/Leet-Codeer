#include <bits/stdc++.h>
using namespace std;
#define v 7
int minkey(int key[], bool mstset[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
    {
        if (mstset[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void printmst(int parent[], int graph[v][v])
{
    cout << " Edge " << "\t Weight" << endl;
    for (int i = 1; i < v; i++)
    {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}
void primsmst(int graph[v][v])
{
    int parent[v];
    int key[v];
    bool mstset[v];
    for (int i = 0; i < v; i++)
    {
        key[i] = INT_MAX;
        mstset[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < v - 1; count++)
    {
        int u = minkey(key, mstset);
        mstset[u] = true;
        for (int j = 0; j < v; j++)
        {
            if (graph[u][j] && mstset[j] == false && graph[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    printmst(parent, graph);
}

int main()
{
    int graph[v][v] = {
        {0, 9, 0, 0, 0, 1, 0},
        {9, 0, 4, 0, 0, 0, 3},
        {0, 4, 0, 2, 0, 0, 0},
        {0, 0, 2, 0, 6, 0, 5},
        {0, 0, 0, 6, 0, 8, 7},
        {1, 0, 0, 0, 8, 0, 0},
        {0, 3, 0, 5, 7, 0, 0},
    };
    primsmst(graph);
}