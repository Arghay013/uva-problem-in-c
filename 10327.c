#include <stdio.h>

const int mx = 1000;

int solve(int n, int arr[])
{
	int i, j, temp, count = 0;

	for(i = 1; i < n; i++){
		for(j = 0; j < n - 1; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count++; 
			}
		}
	}
	return count;
}

int main()
{
	int i, n, arr[mx], ans;

	while(scanf("%d", &n) != EOF)
	{
		for(i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		ans = solve(n, arr);
		printf("Minimum exchange operations : %d\n", ans);
	}	
	return 0;
}