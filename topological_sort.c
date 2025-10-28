#include <stdio.h>

#define MAX 6

int adj[MAX][MAX]; // Adjacency matrix
int inDegree[MAX] = {0}; // In-degree of each vertex
int queue[MAX], front = 0, rear = 0;

// Function for topological sort
void topologicalSort(int V)
{
    // Find in-degree of each vertex
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j])
            {
                inDegree[j]++;
            }
        }
    }

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    printf("Topological Order: ");
    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);
        // Reduce in-degree of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (adj[u][v])
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    queue[rear++] = v;
                }
            }
        }
    }
    printf("\n");
}

// Main function
int main()
{
    int V = 6;

    // Manually add edges: adj[u][v] means u -> v
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V);
    return 0;
}
