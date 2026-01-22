#include <iostream>
using namespace std; 

/*
   just checking for one half - after eliminating one half

   int this array :-

ind: 0  1  2  3  4  5  6  7  8
arr: 7, 8, 9, 1, 2, 3, 4, 5, 6
|           |           |
low         mid         high

TARGET = 1

 ** we have to identify the sorted half **
 */

int search_in_rotated_sorted(int *a, int n, int target) {
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (a[mid] == target)
      return mid;

    // Left half is sorted
    if (a[low] <= a[mid]) {
      if (a[low] <= target && target < a[mid])
        high = mid - 1;
      else
        low = mid + 1;
    }
    // Right half is sorted
    else {
      if (a[mid] < target && target <= a[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int a[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  int n = sizeof(a) / sizeof(a[0]);
  int target = 1;

  int index = search_in_rotated_sorted(a, n, target);

  if (index != -1)
    cout << "Element found at index " << index << endl;
  else
    cout << "Element not found" << endl;

  return 0;
}
