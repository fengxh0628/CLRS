#include <stdio.h>

int linear_search(int a[], int n, int val)
{
  int i, pos = -1;
  for (i = 0; i < n; ++i)
    if (a[i] == val) pos = i;
  return pos;
}

int main()
{
  int a[] = {9, 8, 3, 6, 1, 0, 2, 4, 7, 5};
  int n = sizeof(a) / sizeof(a[0]);
  printf("%d\n", linear_search(a, n, 11));
  return 0;
}
    
  
