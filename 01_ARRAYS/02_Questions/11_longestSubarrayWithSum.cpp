// find the longest subarray with sum k
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK_BRUTE(vector<int> a, int sum) // O(n^2)
{
  int len = 0;
  for (int i = 0; i < a.size(); i++)
  {
    int s = 0;
    for (int j = i; j < a.size(); j++)
    {
      s += a[i];
      if (s == sum)
      {
        len = max(len, j - i + 1);
      }
    }
  }
  return len;
}

int longestSubarrayWithSumK_BETTER(vector<int> a, int sum) {
  
}

int main()
{
  vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
  int requiredSum = 3;
  int x = longestSubarrayWithSumK_BRUTE(arr, requiredSum);
  cout << x;
  return 0;
}
