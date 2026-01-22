#include <stdio.h>
#include <limits.h>

#define MAX 50

int n;

// Find vertex with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1, i;
    for (i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX], visited[MAX];
    int i, count, u, v;

    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < n - 1; count++) {
        u = minDistance(dist, visited);
        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print distances
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int graph[MAX][MAX], i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}

