#include <stdio.h>
#include <stdlib.h>
int BigMod(base,power,mod);

int main()
{
    int base=9;
    int power=101154;
    int mod=11;
    int result=BigMod(base,power,mod);
    printf("%d",result);
}


int BigMod(base,power,mod)
{
    if (power==0)
        return 1;

    if (power%2==0)
    {
        int m1=BigMod(base,power/2,mod)%mod;
        int m2=m1;

        return (m1*m2%mod);
    }

    if (power%2==1)
    {
        int m1=BigMod(base,power-1,mod)%mod;
        int m2=base%mod;

        return (m1*m2)%mod;
    }
}