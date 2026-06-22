// find the second largest element in the array
#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> arr) {
  int largest = INT_MIN;
  int second_largest = INT_MIN;

  int n = arr.size();
  if (n < 2)
    return -1;
  else {
    // find the largest number
    for (int i = 0; i < n; i++) {
      largest = max(largest, arr[i]);
    }

    // find the second largest
    for (int i = 0; i < n; i++) {
      if (arr[i] > second_largest && arr[i] < largest) {
        second_largest = arr[i];
      }
    }
  }

  return second_largest;
}

int main() {
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int result = secondLargest(a);
  cout << result;
  return 0;
}
