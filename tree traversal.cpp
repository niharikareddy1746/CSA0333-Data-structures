#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *l, *r;
};

struct node* newNode(int x)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->l = n->r = NULL;
    return n;
}

void inorder(struct node *t)
{
    if (t) {
        inorder(t->l);
        printf("%d ", t->data);
        inorder(t->r);
    }
}

void preorder(struct node *t)
{
    if (t) {
        printf("%d ", t->data);
        preorder(t->l);
        preorder(t->r);
    }
}

void postorder(struct node *t)
{
    if (t) {
        postorder(t->l);
        postorder(t->r);
        printf("%d ", t->data);
    }
}

int main()
{
    struct node *root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return 0;
}

