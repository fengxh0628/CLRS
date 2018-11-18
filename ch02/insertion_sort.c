#include <stdio.h>

int insertion_sort(int a[], int n)
{
  int j, key, i;
  for (i = 1; i < n; ++i) {
    key = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = key;
  }
}

void print(int a[], int n)
{
  int i;
  for (i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
}

int main()
{
  int a[] = {9, 8, 3, 6, 1, 0, 2, 4, 7, 5};
  int n = sizeof(a) / sizeof(a[0]);
  print(a, n);
  insertion_sort(a, n);
  print(a, n);
  return 0;
}
    
