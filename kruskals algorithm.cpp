#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Edge structure
struct Edge {
    int u, v, w;
};

// Compare function for qsort (ascending weight)
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

// Find set for union-find
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Union two sets
void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Kruskal's algorithm
void kruskal(struct Edge edges[], int E, int V) {
    int parent[MAX], i, count = 0;
    for (i = 0; i < V; i++)
        parent[i] = i;

    qsort(edges, E, sizeof(edges[0]), compare);

    printf("Edge \tWeight\n");

    for (i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int

