#include <stdio.h>

int graph[20][20], visited[20], n;

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            dfs(i);
}

int main() {
    int e, u, v, i, component = 0;
    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &e);
    for (i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("Connected components:\n");
    for (i = 0; i < n; i++)
        if (!visited[i]) {
            component++;
            printf("Component %d: ", component);
            dfs(i);
            printf("\n");
        }
    printf("Total components = %d\n", component);
    return 0;
}
