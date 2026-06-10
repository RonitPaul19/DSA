#include <bits/stdc++.h>
using namespace std;

int bs(const vector<int>& arr, int el) {
  int n = arr.size();

  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == el)
      return mid;
    else if (el > arr[mid])
      high = mid + 1;
    else
      low = mid - 1;
  }

  return -1;
}

int main() {
  vector<int> a = {1, 2, 4, 6, 8, 9};

  int el = 8;

  int result = bs(a, el);

  cout << result << endl;

  return 0;
}
