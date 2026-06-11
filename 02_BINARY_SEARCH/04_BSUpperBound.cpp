// Implement upperbound in binary search
// upper bound for x = smallest index such that a[index] > x
#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int ub_binary(vector<int>& arr, int n, int target) {
  int low = 0, high = n - 1;
  int ans = n;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] > n) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;  // even if the lower bound does not exist we will have a hypothetical lower bound in
               // the nth index
}

int ub_CP(const vector<int>& arr, int n) {
  int ans = upper_bound(arr.begin(), arr.end(), n) - arr.begin();
  return ans;
}

int main() {
  vector<int> arr = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
  int n = 10;
  int el = 6;

  int result = ub_binary(arr, n, el);

  cout << result;
}
