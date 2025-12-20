#include <stdio.h>

int graph[20][20], visited[20];
int n;

/* BFS Function */
void bfs(int start)
{
    int queue[20], front = 0, rear = 0;
    int i;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        start = queue[front++];
        printf("%d ", start);

        for (i = 0; i < n; i++)
        {
            if (graph[start][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

/* Main Function */
int main()
{
    int i, j, start;

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

    bfs(start);

    return 0;
}
