#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

void exchangeSort(int a[], int n) {
  int i = 0, j = 0;  // i => swapping and j => searching for minimum
  for (i = 0; i < n; i++) {
    int mini = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[i]) {
        swap(a[i], a[j]);
      } else {
        // do nothing
      }
    }
  }
}

int main() {
  int a[] = {1, 2, 3, 7, 5, 3, 536, 356, 547, 4, 235, 436};
  int n = sizeof(a) / sizeof(a[0]);

  for (auto el : a) cout << el << " ";
  cout << "\n";

  exchangeSort(a, n);

  for (auto el : a) cout << el << " ";

  return 0;
}
