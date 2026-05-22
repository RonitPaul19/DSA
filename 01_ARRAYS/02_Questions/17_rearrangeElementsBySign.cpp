/*
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative
elements. Without altering the relative order of positive and negative elements,
you must return an array of alternately positive and negative values.
*/
#include <bits/stdc++.h>
using namespace std;

void rearrange_BRUTE(vector<int>& a) {
  vector<int> pos;
  vector<int> neg;

  // Store positives and negatives separately
  for (auto it : a) {
    if (it >= 0)
      pos.push_back(it);
    else
      neg.push_back(it);
  }

  // Place alternatively
  for (int i = 0; i < pos.size(); i++) {
    a[2 * i] = pos[i];      // even index
    a[2 * i + 1] = neg[i];  // odd index
  }
}

void rearrange_OPTIMAL(vector<int>& a) {
  vector<int> temp(a.size());

  int posInd = 0;
  int negInd = 1;

  // Fill temp array
  for (int i = 0; i < a.size(); i++) {
    if (a[i] >= 0) {
      temp[posInd] = a[i];
      posInd += 2;
    } else {
      temp[negInd] = a[i];
      negInd += 2;
    }
  }

  // Copy back to original array
  for (int i = 0; i < a.size(); i++) {
    a[i] = temp[i];
  }
}

int main() {
  vector<int> a = {3, 1, -2, -5, 2, -4};
  rearrange_BRUTE(a);
  for (auto it : a) cout << it << " ";
  return 0;
}
