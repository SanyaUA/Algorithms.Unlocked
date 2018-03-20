#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1
#define DEFAULT_LENGTH 15

void printarr(int arr[], int n);
void generatearr(int arr[], int n);

int generatekey(int lim);
int recursive_binary_search(int arr[], int n, int left, int right, int key);

int main()
{
  int arr[DEFAULT_LENGTH];

  generatearr(arr, DEFAULT_LENGTH);
  printf("\nInput: ");
  printarr(arr, DEFAULT_LENGTH);
  
  int key = generatekey(DEFAULT_LENGTH);
  int index = recursive_binary_search(arr, DEFAULT_LENGTH, 0, DEFAULT_LENGTH, key);

  printf("\nSearching %d in the array ...\n", key);
  printf("[+] %d was founded at index %d.\n", key, index);

  key = generatekey(DEFAULT_LENGTH - 2);
  index = recursive_binary_search(arr, DEFAULT_LENGTH, 0, DEFAULT_LENGTH, key);
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

  for (int i = 0; i < n; i++)
    arr[i] = i + 1;
}

/*
**
** Return index of key in array, or -1 if key not exists in array.
**
*/
int recursive_binary_search(int arr[], int n, int left, int right, int key)
{
  if (left > right) return NOT_FOUND;
  else
  {
    int mid = (left + right) / 2;
    if (arr[mid] == key) return mid;
    else if (arr[mid] > key) return recursive_binary_search(arr, n,left,mid - 1,key );
    else return recursive_binary_search(arr, n, mid + 1, right, key);
  }
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
