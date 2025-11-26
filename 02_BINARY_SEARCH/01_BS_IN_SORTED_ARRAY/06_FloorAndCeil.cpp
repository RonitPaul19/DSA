// floor and ceil in sorted array
// floor - largest number in the array which is <= x
// ceil - smallest number in the array which is >= x
#include <bits/stdc++.h>
using namespace std;

/*
CONCEPT - floor is nothing but lower bound
*/

int findFloor(vector<int> a, int x) {
  int n = a.size();
  int ans = -1;
  int low = 0, high = n-1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] <= mid) {
      ans = a[mid];
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
}

int main() {
  vector<int> a = {10, 20, 30, 40, 50};
  int x = 25; // here floor = 20 , ceil = 30
              // if you have the x itself in the array then floor = ceil = x
  int floor = findFloor(a, x);
  return 0;
}
