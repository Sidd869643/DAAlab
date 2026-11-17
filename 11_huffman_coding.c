#include <stdio.h>

#define MAX 100

typedef struct {
    int weight, parent, left, right;
} Node;

void printCode(Node tree[], int root, char code[], int top) {
    if (tree[root].left == -1 && tree[root].right == -1) {
        int i;
        printf("Symbol %d: ", root + 1);
        for (i = 0; i < top; i++) printf("%c", code[i]);
        printf("\n");
        return;
    }
    if (tree[root].left != -1) {
        code[top] = '0';
        printCode(tree, tree[root].left, code, top + 1);
    }
    if (tree[root].right != -1) {
        code[top] = '1';
        printCode(tree, tree[root].right, code, top + 1);
    }
}

int main() {
    Node t[2 * MAX];
    int n, i, j, x, y, m, min1, min2;
    char code[MAX];

    printf("Enter number of symbols: ");
    scanf("%d", &n);
    if (n < 2 || n > MAX) return 0;

    for (i = 0; i < 2 * n - 1; i++) {
        t[i].parent = t[i].left = t[i].right = -1;
        t[i].weight = 0;
    }
    for (i = 0; i < n; i++) {
        printf("Enter frequency of symbol %d: ", i + 1);
        scanf("%d", &t[i].weight);
    }

    for (m = n; m < 2 * n - 1; m++) {
        min1 = min2 = 1000000000;
        x = y = -1;
        for (i = 0; i < m; i++) {
            if (t[i].parent == -1 && t[i].weight < min1) {
                min2 = min1; y = x;
                min1 = t[i].weight; x = i;
            } else if (t[i].parent == -1 && t[i].weight < min2) {
                min2 = t[i].weight; y = i;
            }
        }
        t[x].parent = t[y].parent = m;
        t[m].weight = t[x].weight + t[y].weight;
        t[m].left = x;
        t[m].right = y;
    }

    printf("Huffman codes:\n");
    printCode(t, 2 * n - 2, code, 0);
    return 0;
}
