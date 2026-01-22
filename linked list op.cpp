#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int x)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = head;
    head = n;
}

void del()
{
    if (head == NULL) return;
    struct node *t = head;
    head = head->next;
    free(t);
}

void display()
{
    struct node *t = head;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main()
{
    int ch, x;
    do {
        printf("\n1-Insert 2-Delete 3-Display 4-Exit: ");
        scanf("%d", &ch);

        if (ch == 1) {
            scanf("%d", &x);
            insert(x);
        }
        else if (ch == 2)
            del();
        else if (ch == 3)
            display();

    } while (ch != 4);

    return 0;
}

