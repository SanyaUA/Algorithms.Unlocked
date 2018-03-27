#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NOT_FOUND -1
#define DEFAULT_LENGTH 10


void printarr(int arr[], int n);
void swap(int * scr, int * dest);
void generatearr(int arr[], int n);
void arraycpy(int dest[], int src[], int from, int to);

void merge_sort(int arr[], int right, int left);
void merge(int arr[], int right, int middle, int left);

int main()
{
  int arr[DEFAULT_LENGTH];

  generatearr(arr, DEFAULT_LENGTH);

  printf("Input: ");
  printarr(arr, DEFAULT_LENGTH);

  printf("\r\nOutput: ");
  merge_sort(arr, 0, DEFAULT_LENGTH - 1);
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
void merge_sort(int arr[], int right, int left)
{
  if (right >= left) return;

  int middle = (right + left) / 2;

  merge_sort(arr, right, middle);
  merge_sort(arr, middle + 1, left);

  merge(arr, right, middle, left);
}
/*
**
** Merging two sorting arrays.
**
*/
void merge(int arr[], int right, int middle, int left)
{
  int n1 = middle - right + 2;
  int n2 = left - middle + 1;

  int temp1[n1];
  int temp2[n2];

  for (int i = right, j = 0; i < middle + 1; i++)
  {
    temp1[j++] = arr[i];
  }

  for (int i = middle + 1, j = 0; i < left + 1; i++)
  {
    temp2[j++] = arr[i];
  }

  temp1[n1 - 1] = INT_MAX;
  temp2[n2 - 1] = INT_MAX;


  int i = 0,
      j = 0,
      k = right;

  while (k <= left)
  {
    if (temp1[i] <= temp2[j])
    {
      arr[k++] = temp1[i++];
    } else if (temp1[i] > temp2[j]) {
      arr[k++] = temp2[j++];
    }
  }
}
