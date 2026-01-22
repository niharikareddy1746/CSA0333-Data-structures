#include <stdio.h>

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1, j = high, temp;

    while (i <= j) {
        while (a[i] <= pivot && i <= high)
            i++;
        while (a[j] > pivot)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    a[low] = a[j];
    a[j] = pivot;

    return j;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pos = partition(a, low, high);
        quickSort(a, low, pos - 1);
        quickSort(a, pos + 1, high);
    }
}

int main() {
    int a[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

