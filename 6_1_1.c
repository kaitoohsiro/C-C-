#include <stdio.h>

int A[5] = {100, 10, 30, 4, 50};

int max(int a, int b) { return a > b ? a : b; }

int findMax(int A[], int l, int r) {
    int m = (l + r) / 2;
    if (l == r - 1) {
        return A[l];
    } else {
        int u = findMax(A, l, m);
        int v = findMax(A, m, r);
        int x = max(u, v);
        return x;
    }
}

int main() {
    int t = findMax(A, 1, 5);
    // int t = findMax(A, 0, sizeof(A) / sizeof(A[0]));
    printf("%d", t);
    return 0;
}