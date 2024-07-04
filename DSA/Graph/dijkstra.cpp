#include <bits/stdc++.h>
using namespace std;
#define v 7
int minkey(int key[], bool mstset[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
    {
        if (mstset[i] == false && key[i] <= min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void printmst(int key[v])
{
    cout << " Edge " << "\t Weight" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << " - " << "\t" << key[i] << endl;
    }
}
void dijkstragraph(int graph[v][v], int src)
{
    int key[v];
    bool mstset[v];
    for (int i = 0; i < v; i++)
    {
        key[i] = INT_MAX;
        mstset[i] = false;
    }
    key[src] = 0;
    for (int count = 0; count < v - 1; count++)
    {
        int u = minkey(key, mstset);
        mstset[u] = true;
        for (int j = 0; j < v; j++)
        {
            if (!mstset[j] && graph[u][j] && key[u] != INT_MAX && key[u] + graph[u][j] < key[j])
            {
                key[j] = key[u] + graph[u][j];
            }
        }
    }
    printmst(key);
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
    dijkstragraph(graph, 0);
}