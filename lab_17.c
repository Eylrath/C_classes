#include<stdio.h>
#include<stdbool.h>
int main()
{
	int number;
	scanf("%d", &number);
	bool prime_arr[number + 1]; 
	for(int i=2; i<number+2; i++)
		prime_arr[i]=true;

	for(int i=2; i<number+2; i++)
	{
		if(prime_arr)
		{
			for(int j = i+i; j<number+2; j=j+i)
				prime_arr[j]=false;
		}
	}
	for(int i=2; i<number+2;i++)
		if(prime_arr[i])
			printf("%d\n", i);
	return 0;
}
       	
