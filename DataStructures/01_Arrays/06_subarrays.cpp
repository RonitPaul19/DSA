/*
Subarrays :- Subarrays are contiguous part of an array
============


Example :-
-------
arr[] = {1,2,3}

All Subarrays of arr[] = {1,2,3}

{1}
{2}
{3}
{1,2}
{2,3}
{1,2,3}

Note:
{1,3} is NOT a subarray because subarrays must be contiguous.


Concepts :=
=========

1. Number of Subarrays in an array of size n = n*(n+1)/2

*/
#include <bits/stdc++.h>
using namespace std;

void printSubarrays_BRUTE(int arr[], int n) {
  for (int start = 0; start < n; start++) {
    for (int end = start; end < n; end++) {
      for (int k = start; k <= end; k++) {
        cout << arr[k] << " ";
      }

      cout << "\n";
    }
  }
}

void printSubarraySum_BRUTE(int arr[], int n) {
  for (int start = 0; start < n; start++) {
    for (int end = start; end < n; end++) {
      int sum = 0;

      for (int k = start; k <= end; k++) {
        sum += arr[k];
      }

      cout << sum << "\n";
    }
  }
}
int main() {
  int arr[] = {1, 2, 3};
  cout << "All subarrays : \n";
  printSubarrays_BRUTE(arr, 3);
  cout << "\n\n";
  cout << "Sum of all subarrays: \n";
  printSubarraySum_BRUTE(arr, 3);
  return 0;
}
