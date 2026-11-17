#include <stdio.h>

int main() {
    int g[20][20] = {0}, indegree[20] = {0}, q[20];
    int n, e, u, v, i, front = 0, rear = 0, count = 0;

    printf("Enter vertices and directed edges: ");
    scanf("%d%d", &n, &e);
    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        g[u][v] = 1;
        indegree[v]++;
    }

    for (i = 0; i < n; i++)
        if (indegree[i] == 0) q[rear++] = i;

    printf("Topological order: ");
    while (front < rear) {
        u = q[front++];
        printf("%d ", u);
        count++;
        for (v = 0; v < n; v++)
            if (g[u][v] && --indegree[v] == 0)
                q[rear++] = v;
    }

    if (count != n) printf("\nGraph contains a cycle; topological sort is impossible.");
    return 0;
}
