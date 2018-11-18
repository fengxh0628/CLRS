#include  <stdio.h>

void selection_sort(int a[], int n)
{
  int i, j, min, tmp;
  for (i = 0; i < n - 1; ++i) {
    min = i;
    for (j = i + 1; j < n; ++j) {
      if (a[j] < a[min]) min = j;
    }
    tmp = a[i]; a[i] = a[min]; a[min] = tmp;
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
  selection_sort(a, n);
  print(a, n);
  return 0;
}
