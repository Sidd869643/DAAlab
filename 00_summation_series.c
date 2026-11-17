#include <stdio.h>

int main() {
    int n, i;
    double sum = 0.0;

    printf("Enter n: ");
    scanf("%d", &n);

    /* Computes 1 + 1/2 + 1/3 + ... + 1/n */
    for (i = 1; i <= n; i++)
        sum += 1.0 / i;

    printf("Sum = %.4lf\n", sum);
    return 0;
}
