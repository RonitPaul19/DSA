#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s) {
  int i = 0;
  int j = s.size() - 1;

  while (i <= j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  string s;
  cin >> s;

  bool result = checkPalindrome(s);

  if (result == true)
    cout << "It is a palindrome";
  else
    cout << "It is not a palindrome";

  return 0;
}
