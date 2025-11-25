// Search insert position
/*
Given a sorted array of nums consisting of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in sorted order.
*/
#include <bits/stdc++.h>
using namespace std;

void searchInsertPositionUtil(const vector<int> &nums, int target, int &ans, int left, int right) {
  if (left > right) {
    return;
  }
  int mid = left + (right - left) / 2;
  if (nums[mid] == target) {
    ans = mid;
    return;
  } else if (nums[mid] < target) {
    ans = mid + 1;
    searchInsertPositionUtil(nums, target, ans, mid + 1, right);
  } else {
    ans = mid;
    searchInsertPositionUtil(nums, target, ans, left, mid - 1);
  }
}

int main() {
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  int ans = -1;
  searchInsertPositionUtil(nums, target, ans, 0, nums.size() - 1);
  cout << ans << endl;
  return 0;
}
