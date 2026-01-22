#include <stdio.h>
#include <limits.h>

#define MAX 50

int n;

// Find vertex with minimum key value not yet included in MST
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index = -1, i;
    for (i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Prim's algorithm
void primMST(int graph[MAX][MAX]) {
    int parent[MAX]; // Store MST
    int key[MAX];    // Minimum weight edge
    int mstSet[MAX]; // Include in MST
    int i, count, u, v;

    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;    // Start from vertex 0
    parent[0] = -1;

    for (count = 0; count < n - 1; count++) {
        u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    printf("Edge \tWeight\n");
    for (i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[MAX][MAX];
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph);

    return 0;
}

