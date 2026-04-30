// find the number that appers once, given that the other numbers appears twice
#include <bits/stdc++.h>
using namespace std;

int fn_BRUTE(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    int num = arr[i];
    int cnt = 0;
    for (int j = 0; j < arr.size(); j++) {
      if (arr[j] == num) {
        cnt++;
      }
    }
    if (cnt == 1) return num;
  }
  return -1;
}

int fn_BETTER(vector<int> arr) {
  // first find the maximum element in the array
  int maxi = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    maxi = max(maxi, arr[i]);
  }

  // create a hash array of size 1 more than the maximum element
  vector<int> hash(maxi + 1);

  for (int i = 0; i < arr.size(); i++) {
    hash[arr[i]]++;
  }

  // check which index stores the value 1 and that index will be the answer
  for (int i = 0; i < hash.size(); i++) {
    if (hash[i] == 1) return i;
  }

  return -1;
}

int fn_OPTIMAL(vector<int> arr) {
  int xorr = 0;

  /*

  = 1 ^ 1 ^ 2 ^ 3 ^ 3 ^ 4 ^ 4
    -----   -   -----   -----

  =   0   ^ 2 ^   0   ^   0

  =   2  **this is the answer

  */

  for (int i = 0; i < arr.size(); i++) {
    xorr ^= arr[i];
  }

  return xorr;
}

int main() {
  vector<int> arr = {1, 1, 2, 3, 3, 4, 4};  // ans = 2

  int result = fn_BRUTE(arr);
  cout << result;

  return 0;
}
