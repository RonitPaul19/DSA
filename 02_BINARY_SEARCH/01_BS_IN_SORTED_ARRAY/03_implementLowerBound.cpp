// implement lower bound
#include <bits/stdc++.h>
using namespace std;

// lower bound implementation
int lowerBound(vector<int> a, int target) {
  int n = a.size();
  int low = 0, high = n - 1;
  int ans = n;

  while (low <= high)
  {
    int mid = (low + high)/2;

    if (a[mid] >= target)
    {
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return ans;
}

// for competitive programming simple way using c++
int lowerBoundCP(vector<int> arr, int target) {
  int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
  return lb;
}

int main() {
  vector<int> a = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
  int x = lowerBoundCP(a, 9);
  cout<<x;
  cout<<endl;
  x = lowerBound(a, 9);
  cout<<x;
  return 0;
}
