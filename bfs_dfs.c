#include <stdio.h>
#define MAX 10

// Adjacency matrix and visited array
int adj[MAX][MAX];
int visited[MAX];

// Function to perform BFS
void bfs(int start, int n)
{
    int queue[MAX], front = -1, rear = -1, i, j;
    queue[++rear] = start;
    visited[start] = 1;
    printf("BFS: ");
    while (front != rear)
    {
        i = queue[++front];
        printf("%d ", i);
        for (j = 1; j <= n; j++)
        {
            if (adj[i][j] && !visited[j])
            {
                visited[j] = 1;
                queue[++rear] = j;
            }
        }
    }
    printf("\n");
}

// Function to perform DFS
void dfs(int start, int n)
{
    int i;
    printf("%d ", start);
    visited[start] = 1;
    for (i = 1; i <= n; i++)
    {
        if (adj[start][i] && !visited[i])
        {
            dfs(i, n);
        }
    }
}

// Main function
int main()
{
    int n, i, j, start;
    printf("Enter the number of nodes (max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter starting node: ");
    scanf("%d", &start);

    // Perform BFS
    bfs(start, n);

    // Reset visited for DFS
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    printf("DFS: ");
    dfs(start, n);
    printf("\n");

    return 0;
}
