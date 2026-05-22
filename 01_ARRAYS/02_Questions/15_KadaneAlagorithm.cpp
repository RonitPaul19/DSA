// KADANE's ALGORITHM
// Given an array of integers, find the subarray with the largest sum and return
// the sum of the elements present in that subarray
#include <bits/stdc++.h>
using namespace std;

int largestSubarraySum_BRUTE(vector<int> a) {
  int maxSum = INT_MIN;
  for (int i = 0; i < a.size(); i++) {
    for (int j = i; j < a.size(); j++) {
      int sum = 0;
      // find the sum of the elements between i and j
      for (int x = i; x <= j; x++) {
        sum += a[x];
      }
      maxSum = max(sum, maxSum);
    }
  }
  return maxSum;
}

int largestSubarraySum_BETTER(vector<int> a) {
  int maxSum = INT_MIN;
  for (int i = 0; i < a.size(); i++) {
    int sum = 0;
    for (int j = i; j < a.size(); j++) {
      sum += a[j];
      maxSum = max(sum, maxSum);
    }
  }
  return maxSum;
}

// ================================================
// OPTIMAL APPRAOCH - KADANES ALGORTHM
// ================================================
int KadaneAlgo(vector<int>& nums) {
  long long maxi = LLONG_MIN;
  long long sum = 0;

  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];

    if (sum > maxi) maxi = sum;

    if (sum < 0) sum = 0;
  }
  return maxi;
}

// HOW TO PRINT THE SUBARRAY HAVING THE MAXIMUM SUM ??
int KadaneAlgo2(vector<int>& nums) {
  long long maxi = LLONG_MIN;
  long long sum = 0;
  int start = -1, end = -1;

  for (int i = 0; i < nums.size(); i++) {
    if (sum == 0) start = i; // The subarray ends when the sum becomes zero (0)

    sum += nums[i];

    if (sum > maxi) {
      maxi = sum;
      int ansStart = start;
      int ansEnd = i;
    }

    if (sum < 0) sum = 0;
  }
  return maxi;
}

int main() {
  vector<int> a = {2, 3, 5, -2, 7, -4};
  int result = KadaneAlgo(a);
  cout << result;
  return 0;
}
