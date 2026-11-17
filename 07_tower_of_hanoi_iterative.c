#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int disk[100];
    int top;
    char name;
} Peg;

void moveDisk(Peg *a, Peg *b) {
    int diskA = (a->top == 0) ? 100000 : a->disk[a->top];
    int diskB = (b->top == 0) ? 100000 : b->disk[b->top];

    if (diskA < diskB) {
        b->disk[++b->top] = a->disk[a->top--];
        printf("Move disk %d from %c to %c\n", b->disk[b->top], a->name, b->name);
    } else {
        a->disk[++a->top] = b->disk[b->top--];
        printf("Move disk %d from %c to %c\n", a->disk[a->top], b->name, a->name);
    }
}

int main() {
    Peg s = {{0}, 0, 'A'}, a = {{0}, 0, 'B'}, d = {{0}, 0, 'C'};
    Peg *src = &s, *aux = &a, *dst = &d, *temp;
    int n, i, total;

    printf("Enter number of disks: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 100) return 0;

    for (i = n; i >= 1; i--) s.disk[++s.top] = i;
    total = (1 << n) - 1;

    if (n % 2 == 0) {
        temp = dst; dst = aux; aux = temp;
    }

    for (i = 1; i <= total; i++) {
        if (i % 3 == 1) moveDisk(src, dst);
        else if (i % 3 == 2) moveDisk(src, aux);
        else moveDisk(aux, dst);
    }
    return 0;
}
