#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue[MAX], front = -1, rear = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS function
void BFS(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int node, i;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        node = dequeue();
        printf("%d ", node);

        for (i = 0);

