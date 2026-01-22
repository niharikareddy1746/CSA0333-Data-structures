#include <stdio.h>

#define MAX 50

int visited[MAX];

// DFS function
void DFS(int graph[MAX][MAX], int n, int start) {
    int i;
    visited[start] = 1;
    printf("%d ", start);

    for (i = 0; i < n; i++) {
        if (graph[start][i] && !visited[i]) {
            DFS(graph, n, i);
        }
    }
}

int main() {
    int n, i, j, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(graph, n, start);

    return 0;
}

