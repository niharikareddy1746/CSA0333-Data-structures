#include <stdio.h>
#include <string.h>
#include <ctype.h>

char st[50];
int top = -1;

int pr(char c)
{
    if (c=='+'||c=='-') return 1;
    if (c=='*'||c=='/') return 2;
    return 0;
}

int main()
{
    char inf[50], pre[50];
    int i, k = 0;

    scanf("%s", inf);
    strrev(inf);

    for (i = 0; inf[i]; i++)
    {
        if (isalnum(inf[i]))
            pre[k++] = inf[i];
        else if (inf[i] == ')')
            st[++top] = inf[i];
        else if (inf[i] == '(')
        {
            while (st[top] != ')')
                pre[k++] = st[top--];
            top--;
        }
        else
        {
            while (top!=-1 && pr(st[top]) > pr(inf[i]))
                pre[k++] = st[top--];
            st[++top] = inf[i];
        }
    }

    while (top!=-1)
        pre[k++] = st[top--];

    pre[k] = '\0';
    strrev(pre);

    printf("%s", pre);
    return 0;
}

