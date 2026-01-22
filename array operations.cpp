#include <stdio.h>
int main() {
    int a[20], n, i, ch, pos, val;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    
    do {
        scanf("%d",&ch);
        if(ch==1){       // Insert
            scanf("%d %d",&pos,&val);
            for(i=n;i>pos-1;i--) a[i]=a[i-1];
            a[pos-1]=val; n++;
        }
        else if(ch==2){  // Delete
            scanf("%d",&pos);
            for(i=pos-1;i<n-1;i++) a[i]=a[i+1];
            n--;
        }
        else if(ch==3){  // Display
            for(i=0;i<n;i++) printf("%d ",a[i]);
            printf("\n");
        }
        else break;
    } while(1);
    return 0;
}

