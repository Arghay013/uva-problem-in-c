#include <stdio.h>
#include <stdlib.h> // for abs

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        int ans = 0;
        int a = n;
        int x;
        while (scanf("%d", &x) == 1) {
            if (x == 0) break;
            a = abs(x - a);
            ans = gcd(ans, a);
            a = x;
        }
        printf("%d\n", ans);
    }
    return 0;
}
