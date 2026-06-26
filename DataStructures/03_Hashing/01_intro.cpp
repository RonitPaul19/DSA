#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cout << "Enter the size of the array : ";
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter element " << i + 1 << ": ";
    cin >> arr[i];
  }

  // precompute
  int hash[13] = {0};  // assume the maximum element that can be stored is 12 (**SUPPOSE**)
  for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }

  int q;
  cout << "Enter the number of time you want to check frequencies of different elements : ";
  cin >> q;
  while (q--) {
    int number;
    cout << "Enter the number you want to check frequencies of : ";
    cin >> number;

    // fetch
    cout << hash[number] << endl;
  }

  return 0;
}
