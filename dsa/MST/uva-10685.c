#include <stdio.h>
#include <string.h>
#define MAXN 5005
#define MAX_NAME_LENGTH 31
int ar[MAXN];
int find(int z) {
    if (ar[z] == z) return z;
    else return find(ar[z]);
}
int main() {
    int i, n, m,j;
    char names[MAXN][MAX_NAME_LENGTH];
    char first[MAX_NAME_LENGTH], second[MAX_NAME_LENGTH];
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        int ans = 0;
        for (i = 1; i <= n; i++) {
            scanf("%s", names[i]);
            ar[i] = i;
        }
        for (i = 0; i < m; i++) {
            scanf("%s%s", first, second);
            int firstNode = 0, secondNode = 0;
            for ( j = 1; j <= n; j++) {
                if (strcmp(first, names[j]) == 0) firstNode = j;
                if (strcmp(second, names[j]) == 0) secondNode = j;
            }
            ar[find(firstNode)] = find(secondNode);
        }
        int mpp[MAXN] = {0};
        for (i = 1; i <= n; i++) {
            ar[i] = find(i); 
            mpp[ar[i]]++; 
            ans = ans > mpp[ar[i]] ? ans : mpp[ar[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}