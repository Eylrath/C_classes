#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, x;
	printf("podaj liczbe: ");
	scanf("%d", &n);
	int tab[n];
	int y;
	printf("adres zmiennej x: %p\nadres tablicy statycznej: %p\nadres zmiennej y: %p\n", &x, tab, &y);
	int* pTab = (int*) malloc(sizeof(int)*n);
	int diff = (int)tab - (int)&x;
	printf("adres tablicy dynamicznej: %p\n", &pTab);
	printf("roznica miedzy x, a poczatkiem statycznej : %d\n", diff);
	free(pTab);
	return 0;

}
	
