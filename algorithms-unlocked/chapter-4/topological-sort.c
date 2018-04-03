#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT_ROWS 3
#define COUNT_COLUMNS 3

void tozero(int * arr, int n);
void printarr(int * arr, int n);
bool has_only_zeroes(int * arr, int n);

void get_matrix(int ** matrix, int n, int m);
void print_matrix(int ** matrix, int n, int m);
int * topological_sort(int ** matrix, int n, int m);

int main()
{
	int ** arr = (int **) malloc(COUNT_ROWS * sizeof(int *));

	for (int i = 0; i < COUNT_ROWS; i++)
		arr[i] = (int *) malloc(COUNT_COLUMNS * sizeof(int));

	get_matrix(arr, COUNT_ROWS, COUNT_COLUMNS);
	print_matrix(arr, COUNT_ROWS, COUNT_COLUMNS);

	int * res = topological_sort(arr, COUNT_ROWS, COUNT_COLUMNS);

	free(res);

	for (int i = 0; i < COUNT_ROWS; i++)
		free(arr[i]);

	free(arr);
	return 0;
}

/*
**
** Get matrix.
**
*/
void get_matrix(int ** matrix, int n, int m)
{
	int val;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;  j < m; j++)
		{
			if (i != j)
			{
				printf("(%d, %d): ", i, j);
				scanf("%d", &val);
				matrix[i][j] = val;
			} else {
				matrix[i][j] = 0;
			}
		}
	}
}

/*
**
** Print matrix.
**
*/
void print_matrix(int ** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		printf(" ");
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\r\n");
	}
}

/*
**
** Print array.
**
*/
void printarr(int * arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

/*
**
** Return sorted array.
**
*/
int * topological_sort(int ** matrix, int n, int m)
{
	int * in_degree = (int *) malloc(sizeof(int) * n);
	tozero(in_degree, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] != 0) in_degree[i]++;
		}
	}

	printf("In degree: ");
	printarr(in_degree, n);

	int count_zero = 0;

	for (int i = 0; i < m; i++)
	{
		if (in_degree[i] == 0) count_zero++;
	}
	printf("\nCount zeroes: %d\n", count_zero);

	int * next = (int *) malloc(sizeof(int) * count_zero);

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (in_degree[i] == 0)
		{
		 	next[j] = i;
		 	j++;
		}
	}
	printf("Next: ");
	printarr(next, count_zero);

	int * res = (int *) malloc(sizeof(int) * count_zero);

	int i = 0;
	j = 0;
	while (!has_only_zeroes(in_degree, count_zero))
	{
		int u = next[j];
		in_degree[j] = 0;
		res[i++] = u;

		for (int k = 0; k < n; k++)
		{
			for (int s = 0; s < m; s++)
			{
				if (matrix[i][j] != 0)
					in_degree[i]--;
				if (in_degree[i] == 0)
					next[j] = i;
			}
		}
	}
	return res;
}

/*
**
** Set all elements of array to zero.
**
*/
void tozero(int * arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}

bool has_only_zeroes(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0) return false;
	}
	return true;
}