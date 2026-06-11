// Implement lowerbound in binary search
// lower bound for x = smallest index such that a[index] >= x
#include <bits/stdc++.h>
using namespace std;

int lb_binary(vector<int>& arr, int n, int target) {
  int low = 0, high = n - 1;
  int ans = n;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] >= n) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;  // even if the lower bound does not exist we will have a hypothetical lower bound in
               // the nth index
}

int main() {
  vector<int> arr = {3, 5, 8, 51, 19};
  int n = 5;
  int el = 8;

  int result = lb_binary(arr, n, el);

  cout << result;
}
