// Floor and ceil in a sorted array
// Floor = largest number in array <= n
// Ceil = smallest number in array >= n
#include <bits/stdc++.h>
using namespace std;

pair<int, int> floorCeil(vector<int>& arr, int x) {
  int n = arr.size();

  int floor = -1;
  int ceil = -1;

  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x) {
      return {arr[mid], arr[mid]};
    }

    if (arr[mid] < x) {
      floor = arr[mid];
      low = mid + 1;
    } else {
      ceil = arr[mid];
      high = mid - 1;
    }
  }

  return {floor, ceil};
}

int main() {
  vector<int> arr = {1, 2, 4, 6, 10, 12};
  int x = 5;

  auto [floor, ceil] = floorCeil(arr, x);

  cout << "Floor = " << floor << '\n';
  cout << "Ceil  = " << ceil << '\n';

  return 0;
}
