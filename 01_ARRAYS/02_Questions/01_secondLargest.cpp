//second largest element in the array without sorting
#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> a) {
  int largest = 0;
  int sLargest = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i]>largest) {
      largest = a[i];
    }
  }
  for (int i = 0; i < a.size(); i++) {
    if (a[i]>sLargest && a[i]<largest) {
      sLargest = a[i];
    }
  }
  return sLargest;
}

int secondLargest_OPTIMAL(const vector<int>& a) {
    if (a.size() < 2) return -1; // or handle error

    int largest = INT_MIN;
    int sLargest = INT_MIN;

    for (int num : a) {
        if (num > largest) {
            sLargest = largest; // old largest becomes second largest
            largest = num;
        } else if (num > sLargest && num < largest) {
            sLargest = num;
        }
    }
    return sLargest;
}

int main() {
  vector<int> a = {1, 3, 0, 3, 9, 5};
  int x = secondLargest_OPTIMAL(a);
  cout<<x;
  return 0;
}
