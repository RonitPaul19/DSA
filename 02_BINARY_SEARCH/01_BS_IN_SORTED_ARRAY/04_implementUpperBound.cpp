#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> a, int target) {
  int n = a.size();
  int low = 0, high = n - 1;
  int ans = n;

  while (low <= high)
  {
    int mid = (low + high)/2;

    if (a[mid] > target)
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

int upperBound_CP(vector<int>a, int target) {
  int lb = upper_bound(a.begin(), a.end(), target) - a.begin();
  return lb;
}

int main() {
  vector<int> a = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
  int x = upperBound(a, 9);
  cout<<x;
  cout<<endl;
  x = upperBound_CP(a, 9);
  cout<<x;
  return 0;
}
