#include<stdio.h>
#include<stdlib.h>

int sgn(int i, int j)
{
	if((i+j)%2==0)
		return 1;
	else
		return -1;
}	

double det(int M[], int n)
{

	if(n==2)
		return M[0] * M[3] - M[1] * M[2];
	else
	{


	
		double sum_det = 0;
		int *Minor = (int *) malloc(sizeof(int) *(n-1)*(n-1));
		for(int k=0; k<n; k++)
		{
			int i_M=0;
			for(int i=0; i<n; i++)
			{
				int j_M=0;
				if(i!=0)
				{
					for(int j=0; j<n; j++)
					{
						if(j!=k)
						{
							*(Minor + i_M*(n-1) +j_M) = *(M + i*n + j);
							j_M++;
						}

					}
					i_M++;
				}
			}

			double x = det(Minor, n-1);
			double y = x * sgn(k,0) * M[k];
		//	printf("%d*%d*%lf\n", sgn(k,0),M[k], x);
		sum_det += y;

		}
		free(Minor);
		return sum_det;
	}
}

int main()
{
	time_t seed;
	srand( (int) seed);
	int rand();

	int N;
	printf("podaj wymiar macierzy NxN: ");
	scanf("%d", &N);

	int *matrix = (int*) malloc(sizeof(int)*N*N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			*(matrix + i*N + j) = rand()%10;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			printf("%5d", *(matrix + i*N + j));
		printf("\n\n");
	}
	printf("%10.3lf", det(matrix,N));
	return 0;
	free(matrix);
}

