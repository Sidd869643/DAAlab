#include <stdio.h>

#define N 20
int residual[N][N], parent[N], n;

int bfs(int source, int sink) {
    int q[N], front = 0, rear = 0, visited[N] = {0}, u, v;
    q[rear++] = source;
    visited[source] = 1;
    parent[source] = -1;

    while (front < rear) {
        u = q[front++];
        for (v = 0; v < n; v++)
            if (!visited[v] && residual[u][v] > 0) {
                q[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
    }
    return visited[sink];
}

int main() {
    int e, u, v, capacity, source, sink, maxFlow = 0, pathFlow, cur, prev;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++) {
        printf("Enter from to capacity: ");
        scanf("%d%d%d", &u, &v, &capacity);
        residual[u][v] += capacity;
    }
    printf("Enter source and sink: ");
    scanf("%d%d", &source, &sink);

    while (bfs(source, sink)) {
        pathFlow = 1000000000;
        for (cur = sink; cur != source; cur = parent[cur]) {
            prev = parent[cur];
            if (residual[prev][cur] < pathFlow)
                pathFlow = residual[prev][cur];
        }

        for (cur = sink; cur != source; cur = parent[cur]) {
            prev = parent[cur];
            residual[prev][cur] -= pathFlow;
            residual[cur][prev] += pathFlow;
        }
        maxFlow += pathFlow;
    }

    printf("Maximum flow = %d\n", maxFlow);
    return 0;
}
