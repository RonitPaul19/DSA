#include <iostream>
#include <vector>
using namespace std;

vector<int> leader_BRUTE(vector<int> a) {
  int n = a.size();
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool leader = true;
    for (int j = i; j < n; j++) {
      if (a[j]>a[i]) {
        leader = false;
        break;
      }
    }
    if (leader == true) {
      ans.push_back(a[i]);
    }
  }
  return ans;
}

vector<int> leader_OPTIMAL(vector<int> a) {
  // if array element is greater than the maximum on the right than it will always be the leader
  int n = a.size();
  vector<int> ans;
  int maxi = INT_MIN;

  for (int i = n-1; i >= 0; i--) {
    if(a[i]>maxi) {
      ans.push_back(a[i]);
    }
    maxi = max(maxi, a[i]);
  }

  return ans;
}

int main() {
  vector<int> a = {10, 22, 12, 3, 0, 6};

  vector<int>result = leader_OPTIMAL(a);

  for (auto item : result) {
    cout<<item<<" ";
  }

  return 0;
}
