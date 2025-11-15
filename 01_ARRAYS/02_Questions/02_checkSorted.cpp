//check if the array is sorted
#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> a) {
  for (int i = 1; i < a.size(); i++) {
    if (a[i] > a[i-1]){}
    else {
      return 0;
    }
  }
  return 1;
}

int main() {
  vector<int> a={1, 2, 0, 3, 5, 9};
  if(isSorted(a)) {
    cout<<"Sorted";
  } else {
    cout<<"Not sorted";
  }
  return 0;
}
