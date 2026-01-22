#include <stdio.h>
#define MAX 5

int s[MAX], top = -1;

int main()
{
    int ch, x;

    do {
        printf("\n1-Push 2-Pop 3-Display 4-Exit: ");
        scanf("%d", &ch);

        if (ch == 1) {
            scanf("%d", &x);
            s[++top] = x;
        }
        else if (ch == 2) {
            top--;
        }
        else if (ch == 3) {
            for (int i = top; i >= 0; i--)
                printf("%d ", s[i]);
        }
    } while (ch != 4);

    return 0;
}

