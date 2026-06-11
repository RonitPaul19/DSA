#include <bits/stdc++.h>
using namespace std;

int bs(const vector<int>& arr, int el) {
  int n = arr.size();

  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == el)
      return mid;
    else if (el > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

int main() {
  vector<int> a = {1, 2, 4, 6, 8, 9};

  int el = 8;

  int result = bs(a, el);

  cout << result << endl;

  return 0;
}

/*

   HOW TO AVOID OVERFLOW CASE IN BINARY SEARCH ? :-

   if we take -

   mid = (low + high) / 2 , THEN IF, low + high = INT_MAX + INT_MAX then integer OVERFLOW

   How to avoid -

   => mid = (low + high) / 2
   => mid = (low - low + low + high) / 2
   => mid = (2*low + high - low) / 2

      --------------------------------------
   => |   mid = low + (high - low) / 2    |     ** USE THIS FORMULA**
      -------------------------------------
 */
