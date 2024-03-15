#include <stdio.h>

int main(){

	int t, a, b, i, sum, j;

	scanf("%d", &t);
	getchar();

	for (i = 1; i <= t; ++i)
	{
		scanf("%d\n%d", &a, &b);
		sum = 0;

		for(j=a; j<=b; j++){
			
			if((j%2) == 1){
				sum += j;
			}

		}

		printf("Case %d: %d\n", i, sum);
	}

	return 0;
}