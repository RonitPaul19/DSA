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

  // Traversal to print all the elements of the array
  for (int i = 0; i < n; i++) cout << arr[i] << " ";

  return 0;
}
