#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int m, n, ans;
char v[MAX_ROWS][MAX_COLS];
bool visited[MAX_ROWS][MAX_COLS];

int di[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dj[] = {1, 0, -1, 1, 0, -1, 1, -1};

void dfs(int a, int b) {
    visited[a][b] = true;
    int I, J;
    for (int i = 0; i < 8; i++) {
        I = a + di[i];
        J = b + dj[i];
        if (I >= 0 && I < m && J >= 0 && J < n && !visited[I][J]) {
            visited[I][J] = true;
            if (v[I][J] == '@') dfs(I, J);
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0) break;

        for (int i = 0; i < m; i++) {
            scanf("%s", v[i]);
        }

        ans = 0;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    if (v[i][j] == '@') {
                        ans++;
                        dfs(i, j);
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
