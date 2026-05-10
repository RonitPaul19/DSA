/*
Find the Majority Element that occurs more than N/2 times

Problem Statement: Given an integer array nums of size n, return the majority
element of the array. The majority element of an array is an element that
appears more than n/2 times in the array. The array is guaranteed to have a
majority element.

*/
#include <bits/stdc++.h>
using namespace std;

int majorityElement_BETTER(vector<int> a) {
  unordered_map<int, int> freq;

  for (auto num : a) {
    freq[num]++;
  }

  for (auto it : freq) {
    if (it.second > a.size() / 2) {
      return it.first;
    }
  }

  return -1;
}

// =============================================================================
// OPTIMAL APPROACH - MOORE'S VOTING ALGORITHM
// =============================================================================
int majorityElement_OPTIMAL(vector<int> v) {
  int cnt = 0;
  int el;

  for (int i = 0; i < v.size(); i++) {
    if (cnt == 0) {
      cnt = 1;
      el = v[i];
    } else if (v[i] == el) {
      cnt++;
    } else {
      cnt--;
    }
  }

  int cnt1 = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == el) cnt1++;
  }

  if (cnt1 > v.size() / 2) return el;
  return -1;
}

int main() {
  vector<int> a = {7, 0, 0, 1, 7, 7, 2, 7, 7};
  int result = majorityElement_OPTIMAL(a);  // 7
  cout << result;
  return 0;
}
