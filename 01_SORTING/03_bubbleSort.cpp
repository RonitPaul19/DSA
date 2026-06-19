#include <bits/stdc++.h>

#include <utility>
using namespace std;

// Bubble sort = push the maximum to the last
// Time complexity - O(n^2) - (Worst complexity)
void bubbleSort(int a[], int n) {
  for (int i = n - 1; i >= 1; i--) {
    int didSwap = 0;
    for (int j = 0; j <= i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        didSwap = 1;
      }
    }
    if (didSwap == 0) break;
  }
}

int main() {
  int arr[] = {1, 3, 9, 2, 4, 9, 6, 7, 1, 3, 2};
  int n = sizeof(arr) / sizeof(int);

  for (auto it : arr) cout << it << " ";

  bubbleSort(arr, n);
  cout << endl;

  for (auto it : arr) cout << it << " ";

  return 0;
}
