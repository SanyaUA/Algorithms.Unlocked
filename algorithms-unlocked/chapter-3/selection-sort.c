#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1
#define DEFAULT_LENGTH 15

void printarr(int arr[], int n);
void swap(int * scr, int * dest);
void generatearr(int arr[], int n);
void selection_sort(int arr[], int n);


int main()
{
  int arr[DEFAULT_LENGTH];

  generatearr(arr, DEFAULT_LENGTH);

  printf("Input: ");
  printarr(arr, DEFAULT_LENGTH);

  printf("\r\nOutput: ");
  selection_sort(arr, DEFAULT_LENGTH);
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
void selection_sort(int arr[], int n)
{
  int smallest;
  for (int i = 0; i < n; i++)
  {
    smallest = i;
    for (int j = i; j < n; j++)
    {
      if (arr[j] < arr[smallest])
	smallest = j;
    }
    swap(&arr[smallest],&arr[i]);
  }
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
