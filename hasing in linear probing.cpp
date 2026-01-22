#include <stdio.h>
#define SIZE 10

int h[SIZE];

int main()
{
    int i, x, key;

    for (i = 0; i < SIZE; i++)
        h[i] = -1;

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &x);
        key = x % SIZE;

        while (h[key] != -1)
            key = (key + 1) % SIZE;

        h[key] = x;
    }

    for (i = 0; i < SIZE; i++)
        printf("%d ", h[i]);

    return 0;
}

