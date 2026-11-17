#include <stdio.h>
#include <stdlib.h>

#define N 4
#define FOUND -1
int goal[16], path[100], solutionDepth = 0, nodes = 0;

int manhattan(int a[]) {
    int i, value, r, c, gr, gc, sum = 0;
    for (i = 0; i < 16; i++) {
        value = a[i];
        if (value == 0) continue;
        r = i / 4; c = i % 4;
        gr = (value - 1) / 4; gc = (value - 1) % 4;
        sum += abs(r - gr) + abs(c - gc);
    }
    return sum;
}

int dfs(int a[], int blank, int g, int bound, int previousMove) {
    int h = manhattan(a), f = g + h;
    int nextBound = 1000000, r = blank / 4, c = blank % 4;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int move, nr, nc, next, temp, result;

    nodes++;
    if (f > bound) return f;
    if (h == 0) {
        solutionDepth = g;
        return FOUND;
    }

    for (move = 0; move < 4; move++) {
        if (move == (previousMove ^ 1)) continue;
        nr = r + dr[move];
        nc = c + dc[move];
        if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;

        next = nr * 4 + nc;
        temp = a[blank]; a[blank] = a[next]; a[next] = temp;
        path[g] = move;
        result = dfs(a, next, g + 1, bound, move);
        temp = a[blank]; a[blank] = a[next]; a[next] = temp;

        if (result == FOUND) return FOUND;
        if (result < nextBound) nextBound = result;
    }
    return nextBound;
}

int main() {
    int a[16], i, blank = -1, bound, result;
    char *moves[] = {"Up", "Down", "Left", "Right"};

    printf("Enter the 4x4 puzzle (use 0 for blank):\n");
    for (i = 0; i < 16; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) blank = i;
    }

    bound = manhattan(a);
    while (bound < 1000000) {
        result = dfs(a, blank, 0, bound, -1);
        if (result == FOUND) {
            printf("Solution found in %d moves:\n", solutionDepth);
            for (i = 0; i < solutionDepth; i++)
                printf("%s ", moves[path[i]]);
            printf("\nNodes explored: %d\n", nodes);
            return 0;
        }
        if (result == 1000000) break;
        bound = result;
    }

    printf("No solution found (or search limit reached).\n");
    return 0;
}
