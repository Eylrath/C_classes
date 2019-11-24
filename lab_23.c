#include<stdio.h>

int NWD(int a, int b)
{
	while(b!=0)
	{
		int c = b;
		b = a - (a/b) * b;
		a = c;
	}
	return a;
}
void skroc(int *a, int *b)
{
	int c = NWD(*a,*b);
	*a /= c;
	*b /=c;
}
int main()
{
	int num1, num2;
	printf("a=");
	scanf("%d", &num1);
	printf("b=");
	scanf("%d", &num2);
	skroc(&num1, &num2);
	printf("\n%d\n_\n%d\n", num1, num2);
	return 0;
}

