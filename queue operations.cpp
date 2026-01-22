#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

int main()
{
    int ch, x, i;

    do {
        printf("\n1-Enq 2-Deq 3-Disp 4-Exit: ");
        scanf("%d", &ch);

        if (ch == 1) {                // Enqueue
            scanf("%d", &x);
            if (rear == MAX - 1) return 0;
            if (front == -1) front = 0;
            q[++rear] = x;
        }
        else if (ch == 2) {           // Dequeue
            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
        else if (ch == 3) {           // Display
            for (i = front; i <= rear; i++)
                printf("%d ", q[i]);
        }
    } while (ch != 4);

    return 0;
}

