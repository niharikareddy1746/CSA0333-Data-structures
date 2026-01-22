#include <stdio.h>

int main() {
    int n, key, low, high, mid, found = 0;
    printf("Enter array size: "); scanf("%d", &n);
    int arr[n];
    printf("Enter sorted elements:\n");
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter number to search: "); scanf("%d", &key);

    low = 0; high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) { found = 1; printf("Found at pos %d\n", mid+1); break; }
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if(!found) printf("Not found\n");
    return 0;
}

