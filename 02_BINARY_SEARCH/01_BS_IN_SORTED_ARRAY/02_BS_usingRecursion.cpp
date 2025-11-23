// recursive way of binary search algorithm
#include <bits/stdc++.h>
using namespace std;

int BS_recursion(vector<int> a, int target, int low, int high) {
  if(low > high) return -1;
  int mid = (low+high)/2;

  if (a[mid] == target)
  {
    return mid;
  }
  else if(target > a[mid]) {
    return BS_recursion(a, target, mid+1, high); // low = mid + 1
  }
  return BS_recursion(a, target, low, mid-1); // high = mid -1
}

int main() {
  vector<int> a = {1, 2, 4, 6, 9, 10};
  int x = BS_recursion(a, 9, 0, 5);
  cout<<x;
  return 0;
}
