//find a number that appears ones and other number twice
#include <bits/stdc++.h>
using namespace std;

int getSingleElement_BRUTE(vector<int> a) { // O(n^2)
  for (int i = 0; i < a.size(); i++)
  {
    int num = a[i];
    int count = 0;
    for (int j = 0; j < a.size(); j++)
    {
      if (a[j] == num)
        count++;
    }
    if (count == 1) return num;
  }
  return -1;
}

int getSingleElement_BETTER(vector<int> a) { // hashing
  // find the maximum element from the array
  int maxi = 0;
  for (int i = 0; i < a.size(); i++) { // O(n)
    maxi = max(maxi, a[i]);
  }
  int hash[maxi] = {0};
  for (int i = 0; i < a.size(); i++) // O(n)
  {
    hash[a[i]]++;
  }
  for (int i = 0; i < a.size(); i++) // O(n)
  {
    if(hash[a[i]] == 1) {
      return a[i];
    }
  }
  return -1;
}

int main()
{

  vector<int> a = {4, 4, 3, 1, 2, 1, 2};
  int x = getSingleElement_BRUTE(a);
  cout<<x;
  return 0;
}
