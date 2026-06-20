// Array rotation
#include <bits/stdc++.h>
using namespace std;

// Left rotate array by one place
/*
Example :- input : arr[] = {1, 2, 3, 4, 5}
           output : arr[] = {2, 3, 4, 5, 1}
*/
// SC - O(1) ; TC - O(n)
void leftRotateby1(vector<int>& arr) {
  int n = arr.size();
  int temp = arr[0];
  for (int i = 1; i < n; i++) arr[i - 1] = arr[i];
  arr[n - 1] = temp;
}

// Left rotate array by K places
void leftRotatebyK_BRUTE(vector<int>& arr, int k) {
  int n = arr.size();
  k = k % n;

  vector<int> temp(k);

  // store first k elements
  for (int i = 0; i < k; i++) {
    temp[i] = arr[i];
  }

  // shift elements left
  for (int i = k; i < n; i++) {
    arr[i - k] = arr[i];
  }

  // put temp back correctly
  for (int i = 0; i < k; i++) {
    arr[n - k + i] = temp[i];
  }
}

void leftRotatebyK_OPTIMAL(vector<int>& arr, int k) {
  int n = arr.size();
  k = k % n;

  reverse(arr.begin(), arr.begin() + k);
  reverse(arr.begin() + k, arr.end());
  reverse(arr.begin(), arr.end());
}

int main() {
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int k = 4;
  for (auto el : a) cout << el << " ";
  leftRotatebyK_OPTIMAL(a, k);
  cout << "\n";
  for (auto el : a) cout << el << " ";
  leftRotatebyK_OPTIMAL(a, k);
  cout << "\n";
  for (auto el : a) cout << el << " ";
  return 0;
}
