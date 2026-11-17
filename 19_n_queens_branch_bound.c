#include <stdio.h>

#define N 20
int n, board[N], col[N], diag1[2 * N], diag2[2 * N], found = 0;

void solve(int row) {
    int c, i;
    if (row == n) {
        found = 1;
        for (i = 0; i < n; i++) {
            for (c = 0; c < n; c++)
                printf("%c ", board[i] == c ? 'Q' : '.');
            printf("\n");
        }
        return;
    }

    for (c = 0; c < n; c++) {
        if (!col[c] && !diag1[row - c + n] && !diag2[row + c]) {
            board[row] = c;
            col[c] = diag1[row - c + n] = diag2[row + c] = 1;
            solve(row + 1);
            col[c] = diag1[row - c + n] = diag2[row + c] = 0;
        }
    }
}

int main() {
    printf("Enter N (use 8 for 8-Queens): ");
    scanf("%d", &n);
    if (n < 1 || n >= N) return 0;
    solve(0);
    if (!found) printf("No solution.\n");
    return 0;
}
