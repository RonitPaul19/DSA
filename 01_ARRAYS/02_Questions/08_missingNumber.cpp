/*
Given an array arr[] of size n-1 with distinct integers in the range of [1, n].
This array represents a permutation of the integers from 1 to n with one element
missing. Find the missing element in the array.
*/
#include <iostream>
#include <vector>
using namespace std;

int missingNum_BRUTE(vector<int>& arr, int n) {
  for (int i = 1; i <= n; i++) {
    bool found = false;

    for (int j = 0; j < arr.size(); j++) {
      if (arr[j] == i) {
        found = true;
        break;
      }
    }

    if (!found) return i;
  }

  return -1;
}

int missingNum_OPTIMAL(vector<int>& arr, int n) {
  int xor1 = 0, xor2 = 0;

  // XOR all array elements
  for (int i = 0; i < n - 1; i++) {
    xor2 ^= arr[i];
  }

  // XOR all numbers from 1 to n
  for (int i = 1; i <= n; i++) {
    xor1 ^= i;
  }

  // Missing number is the XOR of xor1 and xor2
  return xor1 ^ xor2;
}

int main() {
  vector<int> arr = {8, 2, 4, 5, 3, 7, 1};
  int n = 8;
  int res = missingNum_OPTIMAL(arr, n);
  cout << res << endl;
  return 0;
}
