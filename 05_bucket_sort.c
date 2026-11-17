#include <stdio.h>

void insertionSort(float b[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = b[i];
        j = i - 1;
        while (j >= 0 && b[j] > key) {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}

int main() {
    float a[100], bucket[10][100];
    int count[10] = {0}, n, i, b, k = 0;

    printf("Enter number of elements (values from 0 to less than 1): ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%f", &a[i]);

    for (i = 0; i < n; i++) {
        if (a[i] < 0 || a[i] >= 1) {
            printf("All values must be in [0, 1).\n");
            return 1;
        }
        b = (int)(a[i] * 10);
        bucket[b][count[b]++] = a[i];
    }

    for (b = 0; b < 10; b++) {
        insertionSort(bucket[b], count[b]);
        for (i = 0; i < count[b]; i++)
            a[k++] = bucket[b][i];
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%.3f ", a[i]);
    return 0;
}
