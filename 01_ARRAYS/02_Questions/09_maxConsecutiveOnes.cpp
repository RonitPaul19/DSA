// maximum consecutive ones
#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> a) {
  int maxi = 0;
  int cnt = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] == 1)
    {
      cnt++;
      maxi = max(maxi, cnt);
    } else {
      cnt = 0;
    }
  }
  return maxi;
}

int main() {
  vector<int> a = {1, 1, 0, 1, 1, 1, 0, 1, 1};
  int x = maxConsecutiveOnes(a);
  cout<<x;
  return 0;
}
