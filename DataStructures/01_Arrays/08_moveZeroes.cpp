#include <bits/stdc++.h>
using namespace std;

// Move all zeroes to the end of the Array
void MoveZerorsToEnd_BRUTE(vector<int>& arr) {
  // step 1 - Store all the non zero numbers in temp
  vector<int> temp;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] != 0) {
      temp.push_back(arr[i]);
    }
  }
  int totNonZero = temp.size();
}

int main() {
  vector<int> arr = {1, 2, 0, 3, 0, 1, 0, 0, 1, 2, 0, 1, 0, 6};

  for (auto it : arr) cout << it << " ";

  MoveZerorsToEnd_BRUTE(arr);
  cout << "\n";

  for (auto it : arr) cout << it << " ";

  return 0;
}
