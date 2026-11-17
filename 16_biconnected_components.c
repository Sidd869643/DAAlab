#include <stdio.h>

#define N 20
int g[N][N], disc[N], low[N], parent[N], timer = 0;
int stackU[400], stackV[400], top = -1, n;

void push(int u, int v) {
    stackU[++top] = u;
    stackV[top] = v;
}

void printComponent(int u, int v) {
    printf("{ ");
    while (top >= 0) {
        int a = stackU[top], b = stackV[top--];
        printf("(%d-%d) ", a, b);
        if (a == u && b == v) break;
    }
    printf("}\n");
}

void dfs(int u) {
    int v;
    disc[u] = low[u] = ++timer;

    for (v = 0; v < n; v++) {
        if (!g[u][v]) continue;

        if (disc[v] == 0) {
            parent[v] = u;
            push(u, v);
            dfs(v);
            if (low[v] < low[u]) low[u] = low[v];

            if (low[v] >= disc[u])
                printComponent(u, v);
        } else if (v != parent[u] && disc[v] < disc[u]) {
            if (disc[v] < low[u]) low[u] = disc[v];
            push(u, v);
        }
    }
}

int main() {
    int e, u, v, i;
    printf("Enter vertices and undirected edges: ");
    scanf("%d%d", &n, &e);
    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }

    printf("Biconnected components (as edge sets):\n");
    for (i = 0; i < n; i++) {
        if (disc[i] == 0) {
            dfs(i);
            if (top >= 0) printComponent(stackU[0], stackV[0]);
        }
    }
    return 0;
}
