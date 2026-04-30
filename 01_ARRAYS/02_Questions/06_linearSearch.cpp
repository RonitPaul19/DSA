// linear search
#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> a, int x) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == x) return i;
  }
  return 0;
}

int main() {
  vector<int> a = {1, 8, 3, 5, 2, 9, 7};

  int result = linearSearch(a, 10);

  if (result)
    cout << "Element found in index " << result;
  else
    cout << "Element not found";

  return 0;
}
