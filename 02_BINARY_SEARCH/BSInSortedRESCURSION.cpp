#include <bits/stdc++.h>
using namespace std;

// recursive code for the binary search algorithm
int bs_recurse(vector<int>& a, int low, int high, int target) {
  if (low > high) {
    return -1;
  }

  int mid = (low + high) / 2;

  if (a[mid] == target) {
    return mid;
  } else if (target > a[mid]) {
    return bs_recurse(a, mid + 1, high, target);
  } else {
    return bs_recurse(a, low, mid - 1, target);
  }

  return -1;
}

int main() {
  vector<int> a = {3, 4, 6, 7, 9, 12, 16, 16};

  cout << bs_recurse(a, 0, 8, 12);
}
