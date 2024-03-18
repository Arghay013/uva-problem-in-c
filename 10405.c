#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCS(char s1[], char s2[], int len1, int len2) {
    int i, j;
    int lcs[len1 + 1][len2 + 1];
    for (i = 0; i <= len1; i++)
        for (j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    return lcs[len1][len2];
}

int main() {
    char str[1000], s[1000];
    while (fgets(str, sizeof(str), stdin) != NULL && fgets(s, sizeof(s), stdin) != NULL) {
        int l = strlen(str) - 1; // -1 to exclude newline character
        int k = strlen(s) - 1; // -1 to exclude newline character
        printf("%d\n", LCS(str, s, l, k));
    }

    return 0;
}
