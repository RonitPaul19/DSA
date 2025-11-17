//linear searching algorithm in arrays
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int a[], int n, int x) {
  for (int i = 0; i < n; i++) {
  if (a[i] == x) {
      return i;
    }
  }
  return -1;
}

int main() {
  int a[] = {1, 3, 2, 5, 7};
  int n = sizeof(a)/sizeof(int);
  int x = linearSearch(a, n, 5);
  if(x == -1) {
    cout<<"Element not found";
  } else {
  cout<<"Found at index "<<x;
  }
  return 0;
}
