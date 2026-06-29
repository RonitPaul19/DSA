// Maps and unordered maps in cpp
#include <bits/stdc++.h>
using namespace std;

/*

A map consists of key - value pair

map <key, value> var_name
unordered_map <key, value> var_name

*/

int main() {
  // ============ Ordered maps ============
  int n;
  cout << "Enter size of the array :";
  cin >> n;

  int arr[n];

  cout << "Enter " << n << " elements of the array : ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // precompute
  map<int, int> mpp;
  for (int i = 0; i < n; i++) {
    mpp[arr[i]]++;
  }

  // iterate in the map
  // for (auto it : mpp) {
  //   cout << it.first << "->" << it.second << endl;
  // }

  int q;
  cout << "Enter the number of queries : ";
  cin >> q;

  cout << "Enter " << q << " queries : \n";
  while (q--) {
    int number;
    cin >> number;

    // fetch
    cout << mpp[number] << endl;
  }

  return 0;
}
