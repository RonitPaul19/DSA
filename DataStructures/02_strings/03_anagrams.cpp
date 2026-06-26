// Valid anagrams - Given two strings, verify that they are anagrams
#include <bits/stdc++.h>
using namespace std;

// Brute force - O(n log n)
bool verifyAnagrams_BRUTE(string a, string b) {
  if (a.length() != b.length()) return false;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  return a == b;
}

// Optimal - O(n)
bool verifyAnagrams_OPTIMAL(string a, string b) {
  if (a.length() != b.length()) return false;

  unordered_map<char, int> hash;

  // Count frequencies from the first string
  for (char ch : a) hash[ch]++;

  // Remove frequencies using the second string
  for (char ch : b) hash[ch]--;

  // Verify all frequencies are zero
  for (const auto& [ch, count] : hash) {
    if (count != 0) return false;
  }

  return true;
}

int main() {
  string a, b;

  cout << "Enter the first string  : ";
  cin >> a;

  cout << "Enter the second string : ";
  cin >> b;

  bool result = verifyAnagrams_OPTIMAL(a, b);

  if (result)
    cout << "They are anagrams\n";
  else
    cout << "They are not anagrams\n";

  return 0;
}
