#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NOT_FOUND -1
#define DEFAULT_LENGTH 5


void printarr(int arr[], int n);
void swap(int * src, int * dest);
void generatearr(int arr[], int n);

int partition(int arr[], int right, int left);
void quick_sort(int arr[], int right, int left);

int main()
{
  int arr[DEFAULT_LENGTH];

  generatearr(arr, DEFAULT_LENGTH);

  printf("Input: ");
  printarr(arr, DEFAULT_LENGTH);

  printf("\r\nOutput: ");
  quick_sort(arr, 0, DEFAULT_LENGTH - 1);
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
    arr[i] = rand() % n + 1;
}

/*
**
** Return sorted array.
**
*/
void quick_sort(int arr[], int right, int left)
{
  if (right >= left) return;

  int q = partition(arr, right, left);
  
  quick_sort(arr, right, q - 1);
  quick_sort(arr, q + 1, left);
}

/*
**
** Partition for quick sort.
**
*/
int partition(int arr[], int right, int left)
{
  int q = right;

  for (int i = right; i < left; i++)
  {
    if (arr[i] <= arr[left])
    {
      swap(&arr[q], &arr[i]);
      q++;
    } 
  }
  swap(&arr[q], &arr[left]);
  return q;
}

/*
**
** Swap two values.
**
*/
void swap(int * src, int * dest)
{
  int tmp = *src;
  *src = *dest;
  *dest = tmp;
}


