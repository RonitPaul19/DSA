#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cout << "Enter a number : ";
  cin >> n;
  int arr[n];

  // Traversal to take the array elements as input by the user
  cout << "Enter " << n << " elements in the array : ";
  for (int i = 0; i < n; i++) cin >> arr[i];

  int mini = INT_MAX;
  for (int i = 0; i < n; i++) {
    mini = min(mini, arr[i]);
  }

  cout << mini;

  return 0;
}
