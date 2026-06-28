// Maps and unordered maps in cpp
#include <bits/stdc++.h>
using namespace std;

/*

A map consists of key - value pair

map <key, value> var_name
unordered_map <key, value> var_name

*/

int main() {
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // precompute
  map<int, int> mpp;
  for (int i = 0; i < n; i++) {
    mpp[arr[i]]++;
  }

  int q;
  cin >> q;

  while (q--) {
    int number;
    cin >> number;

    // fetch
    cout << mpp[number] << endl;
  }

  return 0;
}
