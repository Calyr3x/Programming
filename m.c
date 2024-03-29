#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 10

struct thread_args
{
    int start;
    int end;
};

int isInverse(int **matrixC, int m, int n)
{
	int flag = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((i == j && matrixC[i][j] == 1) || matrixC[i][j] == 0)
			{
				flag += 1;
			}
		}

	}
	if(flag == m*n) printf("Матрица А обратна матрице В\n");
	else printf("Матрица А не обратна матрице В\n");
}

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int **matrixA;
int **matrixB;
int **matrixC;
int m1 = 0, n1 = 0, m2 = 0, n2 = 0;

void *matrixMulty(void *arg)
{
	struct thread_args * range = (struct thread_args *) arg;
	for(int i = 0; i < m1; i++)
	{
		for(int j = 0; j < n2; j++)
		{
			int thread_private_tmp = 0;
			for(int k = range->start ; k < range->end; k++)
			{
			thread_private_tmp += matrixA[i][k]*matrixB[k][j];
			}
			pthread_mutex_lock(&lock);
			matrixC[i][j] += thread_private_tmp;
			pthread_mutex_unlock(&lock);
		}
	}
}

int** createMatrix(int m, int n)
{
	int** matrix;
	matrix = malloc(m * sizeof(*matrix));
	if(!matrix)
	{
	    fprintf(stderr, "Error allocating memory");
	    exit(-1);
	}

	for(int i = 0; i < m; i++)
	{
	    matrix[i] = malloc(n * sizeof(**matrix));
	    if(!matrix[i])
	    {
	        for(int j = 0; j < i; j++)
	        {
	            free(matrix[j]);
	        }
	        free(matrix);

	        fprintf(stderr, "Error allocating memory");
	        exit(-1);
	    }
	}
	return matrix;
}

void destroyMatrix(int **matrix, int m)
{
	for(int i = 0; i < m; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

int readMatrix(char *fileName, int **matrix, int m, int n)
{
	FILE* fp = fopen(fileName, "r");
	if(!fp)
	{
	   fprintf(stderr, "Error opening '%s'", fileName);
	   exit(-1);
	}

	for(int i = 0; i < m; i++)
	{
	    for(int j = 0; j < n; j++)
	    {
	        fscanf(fp, "%d", &matrix[i][j]);
	    }
	}
	fclose(fp);
	return 0;
}

int printMatrix(char *fileName, int **matrix, int m, int n)
{
	FILE* fp = fopen(fileName, "w");
	if(!fp)
	{
		fprintf(stderr, "Error opening '%s'", fileName);
		exit(-1);
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
	      	fprintf(fp, "%d ", matrix[i][j]);
	    	}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return 0;
}

int printMatrixx(int **matrix, int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
	      	printf("%d ", matrix[i][j]);
	    	}
		printf("\n");
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int rez = 0;
	char *file1, *file2, *output = "result.txt";
	opterr = 0;
	int x = 0;
	while((rez = getopt(argc, argv, "f:m::n::F:M::N::x:")) != -1)
	{
		switch(rez)
		{
		case('f'): file1 = optarg; break;
		case('m'): m1 = atoi(optarg); break;
		case('n'): n1 = atoi(optarg); break;
		case('F'): file2 = optarg; break;
		case('M'): m2 = atoi(optarg); break;
		case('N'): n2 = atoi(optarg); break;
		case('x'): x = atoi(optarg); break;
		case('?'): fprintf(stderr, "-f filename -m num -n num -F filename -M num -N num\n"); exit(-1); break;
		}
	}
	
	if(x)
	{
		m1 = x; 
		m2 = x;
		n1 = x;
		n2 = x;
	}

	pthread_t child_threads[NUM_THREADS];
	struct thread_args work_ranges[NUM_THREADS];
	int current_start, range;
	current_start = 0;
	range = m1 / NUM_THREADS;
	for(int i = 0; i < NUM_THREADS; i++)
	{
      	work_ranges[i].start = current_start;
      	work_ranges[i].end = current_start + range;
      	current_start += range;
	}
	work_ranges[NUM_THREADS-1].end = m1;

	matrixA = createMatrix(m1, n1);
	matrixB = createMatrix(m2, n2);
	matrixC = createMatrix(m1, n2);

	readMatrix(file1, matrixA, m1, n1);
	readMatrix(file2, matrixB, m2, n2);

	for(int i = 0; i < NUM_THREADS; i++)
	{
      	pthread_create(&child_threads[i], NULL, matrixMulty, &work_ranges[i]);
	}
	for(int i = 0; i < NUM_THREADS; i++)
	{
		pthread_join(child_threads[i], NULL);
	}

	destroyMatrix(matrixA, m1);
	destroyMatrix(matrixB, m2);
	printMatrix(output, matrixC, m1, n2);
	isInverse(matrixC, m1, n2);
	destroyMatrix(matrixC, m1);

}
