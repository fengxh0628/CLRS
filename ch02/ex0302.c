#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void merge(int a[], int beg, int mid, int end)
{
  int n1 = mid - beg, n2 = end - mid, i = 0, j = 0, k = beg;
  int *a1 = malloc(sizeof(int) * n1), *a2 = malloc(sizeof(int) * n2);
  memcpy(a1, &a[beg], sizeof(int) * n1);
  memcpy(a2, &a[mid], sizeof(int) * n2);
  while (i < n1 && j < n2)
    if (a1[i] < a2[j]) a[k++] = a1[i++];
    else a[k++] = a2[j++];
  while (i < n1) a[k++] = a1[i++];
  while (j < n2) a[k++] = a2[j++];
}    

void msort(int a[], int beg, int end)
{
  int mid;
  if (beg + 1 < end) {
    mid = (beg + end) / 2;
    msort(a, beg, mid);
    msort(a, mid, end);
    merge(a, beg, mid, end);
  }
}

void print(int a[], int n)
{
  int i;
  for (i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
}

void merge_sort(int a[], int n)
{
  msort(a, 0, n);
}
 
int main()
{
  int a[] = {9, 8, 3, 6, 1, 0, 2, 4, 7, 5};
  int n = sizeof(a) / sizeof(a[0]);
  print(a, n);
  merge_sort(a, n);
  print(a, n);
  return 0;
}
