#include <stdio.h>

int main() {
    int s[100], f[100], n, i, j, temp, count = 0;

    printf("Enter number of activities: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter start and finish time of activity %d: ", i + 1);
        scanf("%d%d", &s[i], &f[i]);
    }

    /* Sort activities by increasing finish time. */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (f[i] > f[j]) {
                temp = f[i]; f[i] = f[j]; f[j] = temp;
                temp = s[i]; s[i] = s[j]; s[j] = temp;
            }

    printf("Selected activities (start, finish):\n");
    j = -1;
    for (i = 0; i < n; i++) {
        if (s[i] >= j) {
            printf("(%d, %d)\n", s[i], f[i]);
            j = f[i];
            count++;
        }
    }
    printf("Maximum activities = %d\n", count);
    return 0;
}
