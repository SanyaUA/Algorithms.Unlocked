#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1
#define DEFAULT_LENGTH 15

void printarr(int arr[], int n);
void generatearr(int arr[], int n);

int generatekey(int lim);
int binary_search(int arr[], int n, int key);

int main()
{
  int arr[DEFAULT_LENGTH];

  generatearr(arr, DEFAULT_LENGTH);
  printf("\nInput: ");
  printarr(arr, DEFAULT_LENGTH);
  
  int key = generatekey(DEFAULT_LENGTH);
  int index = binary_search(arr, DEFAULT_LENGTH, key);

  printf("\nSearching %d in the array ...\n", key);
  printf("[+] %d was founded at index %d.\n", key, index);

  key = generatekey(DEFAULT_LENGTH - 2);
  index = binary_search(arr, DEFAULT_LENGTH, key);
  printf("Searching %d in the array ...\n", key);
  printf("[+] %d was founded at index %d.\n", key, index);

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
** Return index of key in array, or -1 if key not exists in array.
**
*/
int binary_search(int arr[], int n, int key)
{
  int left  = 0;
  int right = n - 1;
  
  int q;
  while (left < right)
  {
    q = (left + right) / 2;
    if (arr[q] == key) return q;
    else if (arr[q] > key) right = q - 1;
    else left = q + 1;
  }

  return NOT_FOUND;
}

/*
**
** Return random integer from range [1, n].
**
*/
int generatekey(int lim)
{
  srand(time(NULL));
  
  return rand() % lim + 1;
}
