#include<stdio.h>

inline char choose_operation(int *a, int *b);
inline int count(int a, int b, int (*pOperation)(int, int));
inline int add(int a, int b);
inline int sub(int a, int b);
inline int mult(int a, int b);
inline int divide(int a, int b);

int main()
{
	int a, b, score;
	char op = choose_operation(&a, &b);
	switch(op)
	{
		case '+':
			score = count(a,b,add);
			break;
		case '-':
			score = count(a,b,sub);
			break;
		case '*':
			score = count(a,b,mult);
			break;
		case '/':
			score = count(a,b,divide);
			break;
		default:
			return 1;
	}
	printf("\na %c b = %d\n", op, score);
}






char choose_operation(int *a, int *b)
{
	char ret;
	printf("podaj operacje(+,*,-,/): ");
	scanf("%c", &ret);
	printf("\na=");
	scanf("%d", a);
	printf("\nb=");
	scanf("%d", b);
	return ret;
}
int add(int a, int b)
{
	return a+b;
}
int sub(int a, int b)
{
	return a-b;
}
int mult(int a, int b)
{
	return a*b;
}
int divide(int a, int b)
{
	return a/b;
}
int count(int a, int b, int (*pOperation)(int, int))
{
	return pOperation(a,b);
}

