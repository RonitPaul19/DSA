// Find the first or last occurrence of a given number in a sorted array
#include <bits/stdc++.h>
using namespace std;

void findFirstLastOccurence_BRUTE(vector<int> a, int x) // O(n)
{
  int first = -1, last = -1;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] == x)
    {
      if (first == -1)
      {
        first = i;
      }
      last = i;
    }
  }
  cout << first << ", " << last;
}

// ===============================================================================================================

// note := if you see nicely - first occurence = lower bound , last occurence = higher bound
int upperBound(vector<int> a, int target)
{ // log(n)
  int n = a.size();
  int low = 0, high = n - 1;
  int ans = n;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (a[mid] > target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

// lower bound implementation
int lowerBound(vector<int> a, int target)
{ // O(log n)
  int n = a.size();
  int low = 0, high = n - 1;
  int ans = n;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (a[mid] >= target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

pair<int, int> findFirstLastOccurence_Better(vector<int> a, int x)
{ // O(2*log(n))
  int lb = lowerBound(a, x);
  if (lb == a.size() || a[lb] != x)
    return {-1, -1};
  return {lb, upperBound(a, x) - 1};
}

// ===============================================================================================================

int findFirst(vector<int>& a, int x) {
    int low = 0, high = a.size() - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == x) {
            first = mid;
            high = mid - 1;  // move left for first occurrence
        }
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}

int findLast(vector<int>& a, int x) {
    int low = 0, high = a.size() - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == x) {
            last = mid;
            low = mid + 1;   // move right for last occurrence
        }
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}

int main()
{
  vector<int> a = {1, 2, 5, 6, 7, 7, 7, 8, 8, 9, 9, 10, 10, 11};
  int x = 7;
  findFirstLastOccurence_BRUTE(a, x);
  cout << "\n";
  pair<int, int> ans = findFirstLastOccurence_Better(a, x);
  cout << ans.first << ", " << ans.second;
  cout << "\n";
  return 0;
}
