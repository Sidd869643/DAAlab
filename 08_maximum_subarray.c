#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int maxCrossing(int a[], int low, int mid, int high) {
    int sum = 0, left = -1000000000, right = -1000000000, i;

    for (i = mid; i >= low; i--) {
        sum += a[i];
        if (sum > left) left = sum;
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++) {
        sum += a[i];
        if (sum > right) right = sum;
    }
    return left + right;
}

int maxSubarray(int a[], int low, int high) {
    int mid, x, y, z;
    if (low == high) return a[low];

    mid = (low + high) / 2;
    x = maxSubarray(a, low, mid);
    y = maxSubarray(a, mid + 1, high);
    z = maxCrossing(a, low, mid, high);
    return max(max(x, y), z);
}

int main() {
    int a[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array (may contain negative values): ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Maximum subarray sum = %d\n", maxSubarray(a, 0, n - 1));
    return 0;
}
