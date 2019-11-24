#include<stdio.h>

int main()
{
	int n, N, i=1;
	scanf("%d", &n);
	N = n*n;
	int left=0, right=n-1, up=0, down=n-1;
	int array[n][n];
	int direction = 0;
	while(i<=N)
	{
		for(int j=left; j<=right; j++)
		{
			array[up][j]=i;
			i++;
		}
		up++;
		for(int j=up; j<=down; j++)
		{
			array[j][right]=i;
			i++;
		}
		right--;
		for(int j=right; j>=left; j--)
		{
			array[down][j]=i;
			i++;
		}
		down--;
		for(int j=down; j>=up; j--)
		{
			array[j][left]=i;
			i++;
		}
		left++;
	}

	for(int j=0; j<n; j++)
	{
		for(int k=0; k<n;k++)
			printf("%4d",array[j][k]);
	        printf("\n");
	}
	return 0;
}	











