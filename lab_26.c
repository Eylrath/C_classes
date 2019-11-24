#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

inline int comp(const char* a, const char* b);
int main()
{
	const int N = 23;
	const int M = 100;
	int size = 0;
	char arr[M][N];
	char input;
	while((input=getchar()) != '\n' && size<M)
	{
		int j = 0;
		while(input != ' '&& input!='\n' && j<N)
		{
			if(input != ' ' && input != '\n' && j<N)
			{
				arr[size][j] = input;
				j++;
			}
			input = getchar();
		}
		arr[size][j]='\0';
		size++;
	}
	
	qsort(arr, sizeof(arr)/szieof(arr[0]),sizeof(arr[0]), comp);
	for(int i=0; i<size;i++)
		printf("%s, ", arr[i]);
	return 0;
}
int comp(const char* a, const char* b)
{
	return strcmp(a,b);
}
	 

