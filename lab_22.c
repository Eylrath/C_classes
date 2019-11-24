#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isnumber(char sign)
{
	if ((char) sign>=48 && (char) sign <=57)
		return 1;
	return 0;
}
int main()
{
	int N = 128;
	char *str1 = (char*) malloc(sizeof(char)*N);
	char *str2 = (char*) malloc(sizeof(char)*N);
	scanf("%[^\n]", str1);
	memccpy(str2, str1, '.', N);
	int length = strlen(str1);
	for(int i=0; i<length; i++)
	{
		if(isnumber(str1[i])==0)
			str1[i]=' ';
	}
	printf("\nwszsykie cyfry z str1: %s\n", str1); 
	printf("dlugosc drugiego skurwiela: %lu\n", strlen(str2));
	printf("wszyskie znaki z str1: %s\n", str2);

}
