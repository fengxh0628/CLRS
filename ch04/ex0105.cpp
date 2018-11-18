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
  submax sb;
  int sum = 0;
  sb.sum = INT_MIN;
  sb.left = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    if (sum > sb.sum) {
      sb.sum = sum;
      sb.right = i + 1;
    } else if (sum < 0) {
      sb.left = i + 1;
      sum = 0;
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
