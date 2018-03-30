#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define RANGE      15
#define NOT_FOUND -1
#define DEFAULT_LENGTH 10

void tozero(int arr[], int n);
void printarr(int arr[], int n);
void generatearr(int arr[], int n);

int * count_keys_less(int arr[], int n);
int * counting_sort(int arr[], int n, int range);
int * count_keys_equal(int arr[], int n, int range);
int * rearrange(int arr[], int less[], int n, int range);

int main()
{
  int arr[DEFAULT_LENGTH];

  generatearr(arr, DEFAULT_LENGTH);

  printf("Input: ");
  printarr(arr, DEFAULT_LENGTH);

  int * result = counting_sort(arr, DEFAULT_LENGTH, RANGE);
  printf("\r\nOutput: ");
  printarr(result, DEFAULT_LENGTH);

  free(result);
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
    arr[i] = rand() % RANGE;
}

/*
**
** Return sorted array.
**
*/
int * counting_sort(int arr[], int n, int range)
{
  int * equal = count_keys_equal(arr, n, range);
  int * less  = count_keys_less(equal, range);

  int * res = rearrange(arr, less, n, range);

  return res; 
}

int * count_keys_equal(int arr[], int n, int range)
{
  int * equal = (int *) malloc(sizeof(int) * range);
  tozero(equal, range);

  int key;
  for (int i = 0; i < n; i++)
  {
    key = arr[i];
    equal[key]++;
  }

  return equal;
}

int * count_keys_less(int arr[], int n)
{
  int * less = (int *) malloc(sizeof(int) * n);
  less[0] = 0;

  for (int j = 1; j < n; j++)
  {
    less[j] = less[j - 1] + arr[j - 1];
  }

  return less;
}
int * rearrange(int arr[], int less[], int n, int range)
{
  int * b = (int *) malloc(sizeof(int) * n);
  int * next = (int *) malloc(sizeof(int) * range);

  for (int j = 0; j < range; j++)
    next[j] = less[j];

  int key, index;
  for (int i = 0; i < n; i++)
  {
    key = arr[i];
    index = next[key];
    b[index] = arr[i];
    next[key]++;
  }

  return b;
}
/*
**
** Set all elements to zero.
**
*/
void tozero(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    arr[i] = 0;
}