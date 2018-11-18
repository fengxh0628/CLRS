#include <iostream>
#include <climits>

struct submax
{
  int left;
  int right;
  int sum;
};

submax find_max_crossing_subarray(int a[], int beg, int mid, int end)
{
  submax sb;
  int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
  for (int i = mid - 1; i >= beg; --i) {
    sum += a[i];
    if (sum > left_sum) {
      left_sum = sum;
      sb.left = i;
    }
  }
  sum = 0;
  for (int i = mid; i < end; ++i) {
    sum += a[i];
    if (sum > right_sum) {
      right_sum = sum;
      sb.right = i + 1;
    }
  }
  sb.sum = left_sum + right_sum;
  return sb;
}

submax find_max_subarray(int a[], int beg, int end)
{
  submax sb, leftsb, rightsb, crosssb;
  if (beg + 1 == end) {
    sb.left = beg;
    sb.right = end;
    sb.sum = a[beg];
  } else {
    int mid = (beg + end) / 2;
    leftsb = find_max_subarray(a, beg, mid);
    rightsb = find_max_subarray(a, mid, end);
    crosssb = find_max_crossing_subarray(a, beg, mid, end);
    if (leftsb.sum >= rightsb.sum && leftsb.sum >= crosssb.sum)
      sb = leftsb;
    else if (rightsb.sum >= leftsb.sum && rightsb.sum >= crosssb.sum)
      sb = rightsb;
    else
      sb = crosssb;
  }
  return sb;
}

int main()
{
  submax sb;
  int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  int n = sizeof(a) / sizeof(a[0]);
  sb = find_max_subarray(a, 0, n);
  std::cout << sb.left << ' ' << sb.right << ' ' << sb.sum << std::endl;
  return 0;
}
  









