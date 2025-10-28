#include <stdio.h>

#define V 4
#define INF 999

// Find minimum key vertex not in MST
int minKey(int key[], int mstSet[])
{
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Prim's algorithm
void prim(int graph[V][V])
{
    int parent[V], key[V], mstSet[V];
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V; i++)
        key[i] = INF, mstSet[i] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d  : %d\n", parent[i], i, graph[i][parent[i]]);
}

// Main function
int main()
{
    int graph[V][V] = {
        {0, 5, 999, 1},
        {5, 0, 2, 999},
        {999, 2, 0, 8},
        {1, 999, 8, 0}
    };

    prim(graph);
    return 0;
}
