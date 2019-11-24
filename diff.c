#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

void read_file(FILE *f, long unsigned *N, char **tab);
// reads fiile f, returns its length and inserts all chars into array

void error();
// procedure to show that error has occured

void print_lines(int beg1, int end1, int beg2, int end2, char t1[], char t2[]);
// procedure to print wrong lines

int main(int argc, char* argv[])
{
	long unsigned n1=0, n2=0;
	char *tab_1, *tab_2;
	char loc1[100], loc2[100];
	FILE *fptr1, *fptr2;
	switch(argc)
	{
		case 1:
			printf("\nwrite location/name of first desired file: ");
			scanf("%s", loc1);	
			printf("\nwrite location/name of second desired file: ");
			scanf("%s", loc2);
			fptr1 = fopen(loc1, "r");
			fptr2 = fopen(loc2, "r");
			break;
		case 2:
			printf("write location/name of second desired file: ");
			scanf("%s", loc1);
			fptr1 = fopen(argv[1], "r");
			fptr2 = fopen(loc1, "r");
			break;
		case 3:
			fptr1 = fopen(argv[1], "r");
			fptr2 = fopen(argv[2], "r");
			break;
		default:
			error(); // less or more values in command line
	}

	read_file(fptr1, &n1, &tab_1);
	read_file(fptr2, &n2, &tab_2);
	
	
	bool prev_good = true, act_good = true;
	int line = 1, idx1 = 0, idx2 = 0, beg1=0, end1=0, beg2=0, end2=0;
	while(idx1<n1 && idx2<n2)
	{

		char s1 = ' ', s2 = ' ';
		while(s1!='\n' && s1!='\0' && s2 !='\n' && s2 != '\0')
		{
			s1 = tab_1[idx1];
			s2 = tab_2[idx2];
			if(s1 != s2)
				act_good = false;
			idx1++;
			idx2++;
		}
		if(!act_good)
		{
			while(s1!='\n' && s1!= '\0')
			{
				s1 = tab_1[idx1];
				idx1++;
			}
			end1 = idx1 - 1;
			while(s2!='\n' && s2!='\0')
			{
				s2 = tab_2[idx2];
				idx2++;
			}
			end2 = idx2 - 1;
		}
		if (!prev_good && act_good)
		{
			print_lines(beg1, end1, beg2, end2, tab_1, tab_2);
			beg1 = idx1, end1 = 0, beg2 = idx2, end2 = 0;
		}
		else if (!act_good && (idx1 >= n1 || idx2 >= n2))
			print_lines(beg1, end1, beg2, end2, tab_1, tab_2);
		prev_good = act_good;
		act_good = true;
	}



	
	return 0;
}

void error()
{
	printf("Something went wrong...\n");
	exit(2);
}
void read_file(FILE *f, long unsigned *N, char **tab)
{
	if(f == NULL)
		error();
	fseek(f, 0, SEEK_END);
	*N = ftell(f);
	fseek(f, 0, SEEK_SET);
	*tab = (char*) malloc((*N)*sizeof(char));
	for(int i=0; i<*N; i++)
		(*tab)[i]=fgetc(f);
}
void print_lines(int beg1, int end1, int beg2, int end2, char t1[], char t2[])
{
	printf("<");
	for(int i=beg1; i < end1; i++)
		printf("%c", t1[i]);
	printf("\n>");
	for(int i=beg2; i < end2; i++)
		printf("%c", t2[i]);
	printf("\n");
}
