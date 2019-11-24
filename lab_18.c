#include<stdlib.h>
#include<stdio.h>
int main()
{
	time_t seed;
	char kostka[6][3][5] = {{"   ", " * ", "   "},
			{"*  ", "   ", "  *"},
			{"*  ", " * ", "  *"},
			{"* *", "   ", "* *"},
			{"* *", " * ", "* *"},
			{"* *", "* *", "* *"}};
	int n = 6;
	srand((unsigned) time(&seed));
	char input = ' ';
	while(input!='k')
	{
		int rand_num = rand() % 6;
		printf("%s \n",kostka[rand_num][0]);
		printf("%s \n",kostka[rand_num][1]);
		printf("%s \n",kostka[rand_num][2]);
		scanf("%c", &input);
	}
	return 0;
}
			
			
			
			
			
