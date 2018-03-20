#include <stdio.h>

#define ULL unsigned long long

ULL factorial(int n);
int main()
{
  printf("\n   *****FACTORIAL*****\n");
  
  int n1 = 3;
  int n2 = 6;
  int n3 = 13;

  printf(" %d! = %lld\n", n1, factorial(n1));
  printf(" %d! = %lld\n", n2, factorial(n2));
  printf(" %d! = %lld\n", n3, factorial(n3));
  
  return 0;
}

/*
** Returns n!.
**
*/
ULL factorial(int n)
{
  if (n == 0) return 1;
  return n * factorial(n - 1);
}
