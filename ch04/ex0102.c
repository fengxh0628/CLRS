#include <iostream>
#include <climits>

struct submax
{
  int left;
  int right;
  int sum;
};

submax find_max_subarray(int a[], int n)
{
  int sum;
  submax sb;
  sb.sum = INT_MIN;
  for (int i = 0; i < n; ++i) {
    sum = 0;
    for (int j = i; j < n; ++j) {
      sum += a[j];
      if (sum > sb.sum) {
	sb.sum = sum;
	sb.left = i;
	sb.right = j + 1;
      }
    }
  }
  return sb;
}

int main()
{
  submax sb;
  int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  int n = sizeof(a) / sizeof(a[0]);
  sb = find_max_subarray(a, n);
  std::cout << sb.left << ' ' << sb.right << ' ' << sb.sum << std::endl;
  return 0;
}
  









