#include <bits/stdc++.h>
using namespace std;

// ---------------- BRUTE FORCE (O(n^3)) ----------------
bool ls(const vector<int>& a, int el) {
  for (int x : a) {
    if (x == el) return true;
  }
  return false;
}

int longestConsecutive_BRUTE(vector<int> a) {
  int n = a.size();
  int bestLen = 0;

  for (int i = 0; i < n; i++) {
    int x = a[i];
    int cnt = 1;

    while (ls(a, x + 1)) {
      x++;
      cnt++;
    }

    bestLen = max(bestLen, cnt);
  }

  return bestLen;
}

// ---------------- BETTER APPROACH (O(n log n)) ----------------
int longestConsecutive_BETTER(vector<int> a) {
  if (a.empty()) return 0;

  sort(a.begin(), a.end());

  int longest = 1;
  int cnt = 1;
  int last = a[0];

  for (int i = 1; i < a.size(); i++) {
    if (a[i] == last) {
      continue;  // skip duplicates
    } else if (a[i] == last + 1) {
      cnt++;
    } else {
      cnt = 1;
    }

    last = a[i];
    longest = max(longest, cnt);
  }

  return longest;
}

// -------------- OPTIMAL APPROACH -------------
int longestConsecutive_OPTIMAL(vector<int> a) {
  int n = a.size();
  if (n == 0) return 0;
  int longest = 1;

  unordered_set<int> st;

  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
  }

  for (auto it : st) {
    if (st.find(it - 1) == st.end()) {
      int cnt = 1;
      int x = it;
      while (st.find(x + 1) != st.end()) {
        x++;
        cnt++;
      }
      longest = max(longest, cnt);
    }
  }

  return longest;
}

// ---------------- MAIN ----------------
int main() {
  vector<int> a = {102, 4, 100, 1, 101, 2, 3, 1, 1};

  cout << "Brute Force Answer: " << longestConsecutive_BRUTE(a) << endl;
  cout << "Better Answer: " << longestConsecutive_BETTER(a) << endl;
  cout << "Optimal Answer: " << longestConsecutive_OPTIMAL(a) << endl;

  return 0;
}
