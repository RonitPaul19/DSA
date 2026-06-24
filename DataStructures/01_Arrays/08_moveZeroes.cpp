#include <bits/stdc++.h>
using namespace std;

// Move all zeroes to the end of the Array
// time complexity = O(n+x+n-x) = O(2n) = O(n)
// space complexity = O(n) -> worst case
void MoveZerorsToEnd_BRUTE(vector<int>& arr) {
  // step 1 - Store all the non zero numbers in temp
  vector<int> temp;
  for (int i = 0; i < arr.size(); i++) {  // O(n)
    if (arr[i] != 0) {
      temp.push_back(arr[i]);
    }
  }
  int totNonZero = temp.size();

  // step 2 - put all temp elements in the front
  for (int i = 0; i < totNonZero; i++) {  // O(x)
    arr[i] = temp[i];
  }

  // step 3 - filling zeroes in the remaining index
  for (int i = totNonZero; i < arr.size(); i++) {  // O(n-x)
    arr[i] = 0;
  }
}

// OPTIMAL - 2 pointer apprach
// time complexity = O(n)
// space complexity = O(1)
void MoveZerorsToEnd_OPTIMAL(vector<int>& arr) {
  // step 1 -> find the first zero and the index will be pointed by 'j'
  int j = -1;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == 0) {
      j = i;
      break;
    }
  }

  if (j == -1) return;  // if the array has no zeroes terminate the program

  // step 2 -> i = j + 1
  for (int i = j + 1; i < arr.size(); i++) {
    if (arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

int main() {
  vector<int> arr = {1, 2, 0, 3, 0, 1, 0, 0, 1, 2, 0, 1, 0, 6};

  for (auto it : arr) cout << it << " ";

  MoveZerorsToEnd_BRUTE(arr);
  cout << "\n";

  for (auto it : arr) cout << it << " ";

  return 0;
}
