#include <stdio.h>

#define INF 9999

int main()
{
    int n;
    int graph[20][20];
    int distance[20];
    int visited[20];
    int i, j, source;
    int min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if(graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++)
    {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    for(i = 1; i < n; i++)
    {
        min = INF;
        next = -1;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 && distance[j] < min)
            {
                min = distance[j];
                next = j;
            }
        }

        if(next == -1)
            break;

        visited[next] = 1;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 &&
               distance[next] + graph[next][j] < distance[j])
            {
                distance[j] = distance[next] + graph[next][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        if(distance[i] == INF)
            printf("Vertex %d = Not reachable\n", i);
        else
            printf("Vertex %d = %d\n", i, distance[i]);
    }

    return 0;
}