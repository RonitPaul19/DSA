// Given a sorted array of distinct integers and a target value, return the index if the target is
// found. If not, return the index where it would be if it were inserted in order. You must write an
// algorithm with O(log n) runtime complexity.
#include <bits/stdc++.h>
using namespace std;

/*

   arr[]={1,2,4,7}     x=6
                \      /
      arr[] = {1, 2, 4, 6, 7}
               0  1  2  3  4
                        ^

   ans = 3

*/

int searchInsertPosition(vector<int> arr, int x) {
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = n;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] >= x) {
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
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << searchInsertPosition(a, 7);

  return 0;
}
