// Maximum consecutive ones
#include <bits/stdc++.h>
using namespace std;

// TC = O(n)
int maximumConsecutiveOnes(vector<int> arr) {
  int maxi = 0;
  int cnt = 0;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == 1) {
      cnt++;
      maxi =
          max(cnt, maxi);  // to find and take the largest between cnt and maxi
    } else {
      cnt = 0;  // if 1 not found that means consecutiveness is broken and cnt
                // reset to 0
    }
  }

  return maxi;
}

int main() {
  vector<int> arr = {1, 1, 1, 0, 1, 1, 1, 0, 1, 1};  // the answer will be 3

  int result = maximumConsecutiveOnes(arr);
  cout << result;

  return 0;
}
