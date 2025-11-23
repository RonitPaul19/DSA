// binary search to find X in a sorted array
#include <bits/stdc++.h>
using namespace std;

int BS(vector<int> a, int x) {
  int low = a[0];
  int high = a[a.size()-1];

  while(low <= high) {
    int mid = (low+high)/2;

    if (a[mid] == x) {
      return mid;
    }
    else if(x > a[mid]) {
      low = mid + 1;
    }
    else {
      high = mid -1;
    }
  }
  return -1;
}

int main() {
  vector<int> a = {1, 2, 4, 6, 9, 10};
  int x = BS(a, 10);
  cout<<x;
  return 0;
}
