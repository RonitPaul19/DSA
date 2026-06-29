// Maps and unordered maps in cpp
#include <bits/stdc++.h>
using namespace std;

/*

A map consists of key - value pair

map <key, value> var_name
unordered_map <key, value> var_name

*/

/*
Storing or fetching in a ordered map ->
                                O(log n) [where n is the number of elements present in the map]

Storing or fetching in a unordered map ->
                                O(1) [where n is the number of elements present in the map]

                                [  Average and Best -> O(1)  ] <- Mostly used
                                [  Worst -> O(n)             ]
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

  // ============ Unordered maps ============ <- First preferece
  int n2;
  cout << "Enter size of the array :";
  cin >> n2;

  int arr2[n2];

  cout << "Enter " << n2 << " elements of the array : ";
  for (int i = 0; i < n2; i++) {
    cin >> arr2[i];
  }

  // precompute
  unordered_map<int, int> mpp2;
  for (int i = 0; i < n2; i++) {
    mpp2[arr2[i]]++;
  }

  // iterate in the map
  // for (auto it : mpp) {
  //   cout << it.first << "->" << it.second << endl;
  // }

  int q2;
  cout << "Enter the number of queries : ";
  cin >> q2;

  cout << "Enter " << q2 << " queries : \n";
  while (q2--) {
    int number2;
    cin >> number2;

    // fetch
    cout << mpp2[number2] << endl;
  }

  return 0;
}
