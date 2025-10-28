#include <stdio.h>

#define V 4

int parent[V];

// Find set of element i
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union of two sets
void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Kruskal's algorithm
void kruskal(int cost[V][V])
{
    int mincost = 0, num_edges = 0;

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    while (num_edges < V - 1)
    {
        int min = 999, u = -1, v = -1;

        // Find minimum weight edge
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u != -1 && v != -1)
        {
            printf("Edge %d-%d: %d\n", u, v, min);
            mincost += min;
            union1(u, v);
            num_edges++;
        }
    }
    printf("Minimum cost: %d\n", mincost);
}

// Main function
int main()
{
    int cost[V][V] = {
        {0, 5, 999, 1},
        {5, 0, 2, 999},
        {999, 2, 0, 8},
        {1, 999, 8, 0}
    };

    kruskal(cost);
    return 0;
}
