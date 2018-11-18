#include <stdio.h>
#include <stdlib.h>

int* binary_add(int a[], int b[], int n)
{
  int *c = malloc(sizeof(int) * (n + 1));
  int i, carry = 0;
  for (i = n; i > 0; --i) {
    c[i] = a[i - 1] + b[i - 1] + carry;
    if (c[i] > 1) {
      c[i] -= 2;
      carry = 1;
    } else carry = 0;
  }
  c[0] = carry;
  return c;
}

void print(int a[], int n)
{
  int i;
  for (i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
}

int main()
{
  int a[] = {1, 0, 1, 0, 1, 1};
  int b[] = {1, 1, 0, 0, 1, 1};
  int n = sizeof(a) / sizeof(a[0]);
  int *c = binary_add(a, b, n);
  print(c, n + 1);
  free(c);
  return 0;
}
