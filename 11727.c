#include <stdio.h>

int main()
{
    int test, x, y, z, i;
    scanf("%d", &test);

    for (i = 0; i < test; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if ((y > x && x > z) || (y < x && x < z))
            printf("Case %d: %d\n", i + 1, x);
        else if ((x > y && y > z) || (x < y && y < z))
            printf("Case %d: %d\n", i + 1, y);
        else
            printf("Case %d: %d\n", i + 1, z);
    }
    return 0;
}