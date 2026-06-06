// NEXT PERMUTATION - Given an array Arr[] of integers, rearrange the numbers of the given array
// into the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e.,
// sorted in ascending order).
#include <bits/stdc++.h>
using namespace std;

void nextGreaterPermutation_BETTER(vector<int> a) { next_permutation(a.begin(), a.end()); }

vector<int> nextGreaterPermutation(vector<int> a) {
  int ind = -1;
  int n = a.size();

  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      ind = i;
      break;
    }
  }

  if (ind == -1) {
    reverse(a.begin(), a.end());
    return a;
  }

  for (int i = n - 1; i > ind; i--) {
    if (a[i] > a[ind]) {
      swap(a[i], a[ind]);
      break;
    }
  }

  reverse(a.begin() + ind + 1, a.end());  // remember that we do not have to reverse the entire
                                          // array, reverse only the part after the breakpoint

  return a;
}

int main() {
  vector<int> a = {1, 2, 9, 3, 2, 7, 8};
  vector<int> result = nextGreaterPermutation(a);

  for (auto el : result) cout << el << " ";

  return 0;
}
