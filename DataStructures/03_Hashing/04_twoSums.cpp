// Two sum
#include <bits/stdc++.h>

#include <utility>
using namespace std;

string twoSum_BRUTE(vector<int> arr, int target) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[i] + arr[j] == target) {
        return "YES";  // return {i, j};
      }
    }
  }
  return "NO";  // return {-1, -1};
}

// Notes : This is the most important
string twoSum_BETTER(vector<int> arr, int target) {
  map<int, int> mpp;

  for (int i = 0; i < arr.size(); i++) {
    int a = arr[i];
    int more = target - a;
    if (mpp.find(more) != mpp.end()) {
      return "YES";  // return {mpp[moreNeeded], i};
    }
    mpp[a] = i;
  }
  return "NO";  // return {-1, -1};
}

string twoSum_OPTIMAL(vector<int> arr, int target) {
  int left = 0, right = arr.size() - 1;

  sort(arr.begin(), arr.end());
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target)
      return "YES";
    else if (sum < target)
      left++;
    else if (sum > target)
      right--;
  }
  return "NO";
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int target = 12;

  cout << twoSum_BRUTE(arr, target);
  cout << endl;
  cout << twoSum_BETTER(arr, target);
  cout << endl;
  cout << twoSum_OPTIMAL(arr, target);

  return 0;
}
