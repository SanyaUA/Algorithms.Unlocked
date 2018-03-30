#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define RANGE      2
#define NOT_FOUND -1
#define DEFAULT_LENGTH 10


void printarr(int arr[], int n);
void generatearr(int arr[], int n);

void really_simple_sort(int arr[], int n);

int main()
{
  int arr[DEFAULT_LENGTH];

  generatearr(arr, DEFAULT_LENGTH);

  printf("Input: ");
  printarr(arr, DEFAULT_LENGTH);

  printf("\r\nOutput: ");
  really_simple_sort(arr, DEFAULT_LENGTH);
  printarr(arr, DEFAULT_LENGTH);

  return 0;
}

/*
**
** Print array into the stdout(console).
**
*/
void printarr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}

/*
**
** Return random n-length array, range for random values is [1, n].
**
*/
void generatearr(int arr[], int n)
{
  srand(time(NULL));

  for (int i = 0; i < n; i++)
    arr[i] = rand() % RANGE + 1;
}

/*
**
** Return sorted array.
**
*/
void really_simple_sort(int arr[], int n)
{
  int k = 0;

  for (int i = 0; i < n; i++)
    if (arr[i] == 1) k++;

  for (int i = 0; i < k; i++)
    arr[i] = 1;

  for (int i = k + 1; i < n; i++)
    arr[i] = 2;
}