#include <stdio.h>

#define MAXN 30000

int Parent[MAXN];
int sz[MAXN];
int componentsCount;

void init(int N) {
    componentsCount = N;
    for (int i = 0; i < N; i++) {
        Parent[i] = i;
        sz[i] = 1;
    }
}

int find(int p) {
    while (p != Parent[p])
        p = Parent[p];
    return p;
}

void makeUnion(int p, int q) {
    int i = find(p);
    int j = find(q);
    if (i == j)
        return;
    if (sz[i] < sz[j]) {
        Parent[i] = j;
        sz[j] += sz[i];
    } else {
        Parent[j] = i;
        sz[i] += sz[j];
    }
    componentsCount--;
}

int main() {
    int n, m, a, b, i, test;
    scanf("%d", &test);
    while (test--) {
        scanf("%d %d", &n, &m);
        init(n);
        for (i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            makeUnion(a, b);
        }
        int ans = 0;
        for (i = 0; i < n; i++) {
            if (sz[i] > ans)
                ans = sz[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
