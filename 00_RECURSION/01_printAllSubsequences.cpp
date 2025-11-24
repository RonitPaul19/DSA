// print all the subsequences of an array using recursion
#include <bits/stdc++.h>
using namespace std;

void printF(int ind, vector<int> &ds, int arr[], int n) {
  if(ind >= n) {
    if(ds.size() == 0) {
      cout<<"{}";
    } else {
      for(auto it : ds) {
        cout<<it<<" ";
      }
    }
    cout<<"\n";
    return;
  }

  // take
  ds.push_back(arr[ind]);
  printF(ind+1, ds, arr, n);
  ds.pop_back();

  // not take
  printF(ind+1, ds, arr, n);
}

int main() {
  int arr[] = {3, 1, 2};
  int n = 3;
  vector<int> ds;
  printF(0, ds, arr, n);
  return 0;
}
