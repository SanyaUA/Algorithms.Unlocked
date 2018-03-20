#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1
#define DEFAULT_LENGTH 15

void printarr(int arr[], int n);
void swap(int * scr, int * dest);
void generatearr(int arr[], int n);
void insertion_sort(int arr[], int n);


int main()
{
  int arr[DEFAULT_LENGTH];

  generatearr(arr, DEFAULT_LENGTH);

  printf("Input: ");
  printarr(arr, DEFAULT_LENGTH);

  printf("\r\nOutput: ");
  insertion_sort(arr, DEFAULT_LENGTH);
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
void insertion_sort(int arr[], int n)
{
  int key;
  int j;

  for (int i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
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
