#include <stdio.h>
#include <string.h>

#define LEN 100005 // セミコロンいらない

// 構造体の型を定義する
typedef struct pp {
    char name[100];
    int t;
} P; // これを以後pとして扱う


P Q[LEN]; // int tみたいなノリ
int head, tail, n;

void enqueue(P x) {
    Q[tail] = x;
    tail = (tail + 1) % LEN;
}

P dequeue() {
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
}

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int elaps = 0, c;
    int i, q;
    P u;
    scanf("%d %d", &n, &q);

    for ( i = 1; i <= n; i++ ) {
        scanf("%s", Q[i].name);  // 文字列は直接
        scanf("%d", &Q[i].t);   // 数値系はアドレス参照？？
    }
    head = 1; tail = n - 1;

    while ( head != tail ) {
        u = dequeue();
        c = min(q, u.t);
        u.t -= c;
        elaps += c;
        if ( u.t > 0 ) {
            enqueue(u);
        } else {
            printf("%s %d\n", u.name, elaps);
        }
    }
    return 0;
}