#include <bits/stdc++.h>
using namespace std;

int main() {
  string name;

  cout << "Enter your full name: ";
  getline(cin, name);  // Used to input a string with spaces
  cout << "Your full name is: " << name << endl;

  int length = name.size();  // Used to find the length/size of the string
  cout << "The length of your name is " << length << endl;

  return 0;
}
