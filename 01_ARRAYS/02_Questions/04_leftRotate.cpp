// array left rotation
#include <bits/stdc++.h>
using namespace std;

// left rotate an array by 1 place
vector<int> leftRotate1_BRUTE(vector<int>& arr) {
  int n = arr.size();
  if (n == 0) return arr;

  vector<int> temp(n);

  for (int i = 1; i < n; i++) {
    temp[i - 1] = arr[i];
  }

  temp[n - 1] = arr[0];

  return temp;
}

void leftRotate1_OPTIMAL(vector<int>& arr) {
  int temp = arr[0];

  for (int i = 1; i < arr.size(); i++) {
    arr[i - 1] = arr[i];
  }

  arr[arr.size() - 1] = temp;
}

// TC - O(k + n - k + k) = O(n + k)
// SC - O(k)
void leftRotateByK_BRUTE(vector<int>& arr, int k) {
  int n = arr.size();
  if (n == 0) return;
  k = k % n;

  vector<int> temp(k);

  for (int i = 0; i < k; i++) {  // O(k)
    temp[i] = arr[i];
  }

  for (int i = k; i < n; i++) {  // O(n-k)
    arr[i - k] = arr[i];
  }

  // int j = 0;
  // for (int i = n - k; i < n; i++) {
  //   arr[i] = temp[j];
  //   j++;
  // }

  // MATHEMATICALLY
  for (int i = n - k; i < n; i++) {  // O(k)
    arr[i] = temp[i - (n - k)];
  }
}

void reverse(vector<int>& arr, int start, int end) {
  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

// left rotate optimal approach
// arr = {1, 2, 3, 4, 5, 6} ; int k = 3
// part 1 = {1, 2, 3} -> rotate -> {3, 2, 1}
// part 2 = {4, 5, 6} -> rotate -> {6, 5, 4}
// join part 1 and part 2 = {3, 2, 1, 6, 5, 4}
// rotate the entire array -> {4, 5, 6, 1, 2, 3} -> This is the answer :)
void leftRotateByK_OPTIMAL(vector<int>& arr, int k) {
  int n = arr.size();
  if (n == 0) return;

  k = k % n;

  reverse(arr, 0, k - 1);
  reverse(arr, k, n - 1);
  reverse(arr, 0, n - 1);
}

int main() {
  vector<int> a = {1, 2, 3, 4, 5};
  cout << "Before left rotate by 1" << "\n";
  for (int el : a) {
    cout << el << " ";
  }
  cout << "\n";

  leftRotate1_OPTIMAL(a);

  cout << "after left rotate by 1" << "\n";
  for (int el : a) {
    cout << el << " ";
  }
  cout << "\n";

  int d = 3;
  leftRotateByK_OPTIMAL(a, d);
  cout << "After rotating the array by " << d << " places";
  for (int el : a) {
    cout << el << " ";
  }
  cout << "\n";
  return 0;
}
