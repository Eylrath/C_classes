#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 16, i = 0, j = 1;
	char* pTab = (char*) malloc(sizeof(char)*n);
	char sign = ' ';
	while(sign != '\n')
	{
		sign = getchar();
		if(i == j * n)
		{
			j++;
			pTab = realloc(pTab, sizeof(char)*j*n);
		}
		pTab[i] = sign;
		i++;
	}
	for(int k = 0; k < i ; k++)
		printf("%c", pTab[k]);
	free(pTab);
}

