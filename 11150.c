#include <stdio.h>
int main ()
{
    int n,count;
    while (scanf("%d",&n)==1)
    {
        count=n;
        while (n>1)
        {
            if (n==2)
            {
                count+=1;
                break;
            }
            else
            {
                count+=(n/3);
                n=n/3+n%3;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}