//find the missing number from an array of size (n - 1) for a given value n
#include <bits/stdc++.h>
using namespace std;

int findMissing_BRUTE(vector<int> a, int n) {
  int sumOfN = 0;
  int sumOfArray = 0;

  for (int i = 1; i <= n; i++)
  {
    sumOfN += i;
  }
  for (int i = 0; i < a.size(); i++)
  {
    sumOfArray += a[i];
  }

  return (sumOfN - sumOfArray);
}

int findMissing_OPTIMAL(vector<int> a, int n) {
  int xor1 = 0;
  int xor2 = 0;
  for(int i = 1; i <= n; i++) { // xor of max bound of number
    xor1 ^= i;
  }
  for(int i = 0; i < a.size(); i++) { // xor of all the elements in the array
    xor2 ^= a[i];
  }
  return xor1^xor2;
}

int main() {
  int n = 5;
  vector<int> a = {1, 2, 4, 5};
  int x = findMissing_BRUTE(a, n);
  cout<<x;
  cout<<endl;
  int y = findMissing_OPTIMAL(a, n);
  cout<<y;

  return 0;
}
