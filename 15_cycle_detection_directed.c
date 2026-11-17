#include <stdio.h>

int g[20][20], color[20], n;

int dfs(int u) {
    int v;
    color[u] = 1; /* currently in recursion stack */

    for (v = 0; v < n; v++) {
        if (g[u][v]) {
            if (color[v] == 1) return 1;
            if (color[v] == 0 && dfs(v)) return 1;
        }
    }
    color[u] = 2; /* completely processed */
    return 0;
}

int main() {
    int e, u, v, i, cycle = 0;
    printf("Enter vertices and directed edges: ");
    scanf("%d%d", &n, &e);
    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        g[u][v] = 1;
    }

    for (i = 0; i < n; i++)
        if (color[i] == 0 && dfs(i)) {
            cycle = 1;
            break;
        }

    if (cycle) printf("Cycle exists in directed graph.\n");
    else printf("No cycle in directed graph.\n");
    return 0;
}
