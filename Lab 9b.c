#include <stdio.h>

int graph[20][20], visited[20];
int n;

/* DFS Function */
void dfs(int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

/* Main Function */
int main()
{
    int i, j, start;
    int connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dfs(start);

    /* Check if all vertices are visited */
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The given graph is CONNECTED.");
    else
        printf("The given graph is NOT CONNECTED.");

    return 0;
}
