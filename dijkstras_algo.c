#include <stdio.h>
#include <limits.h>

#define V 5   // number of vertices

void dijkstra(int graph[V][V], int src)
{
    int dist[V], visited[V];

    // initialize distance and visited arrays
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    // find shortest paths
    for (int count = 0; count < V - 1; count++)
    {
        int min = INT_MAX, u = -1;

        // pick the unvisited vertex with smallest distance
        for (int i = 0; i < V; i++)
            if (!visited[i] && dist[i] < min)
                min = dist[i], u = i;

        visited[u] = 1;

        // update distances of neighbors
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}

int main()
{
    int graph[V][V] = {
        {0, 4, 0, 0, 8},
        {4, 0, 8, 0, 11},
        {0, 8, 0, 7, 0},
        {0, 0, 7, 0, 2},
        {8, 11, 0, 2, 0}
    };

    int src;
    printf("Enter source vertex (0-%d): ", V - 1);
    scanf("%d", &src);

    dijkstra(graph, src);
    return 0;
}
