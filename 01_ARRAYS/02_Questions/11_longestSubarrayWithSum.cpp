// FIND THE LONGEST SUBARRAY WITH SUM = K
#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
🧠 THEORY:

👉 Subarray = contiguous part of array

👉 Types of solutions:
1. Brute Force (O(n^3))
2. Improved Brute (O(n^2))
3. Prefix Sum + HashMap (O(n)) → works for ALL cases
4. Sliding Window (O(n)) → ONLY for positives (and zero)

================================================================================
*/

// ----------------------------------------------------------------------------
// 🔴 1. BRUTE FORCE (O(n^3))
// ----------------------------------------------------------------------------
int longestSubarrayWithSum_BRUTE(vector<int> arr, int k)
{
  int len = 0;

  // generate all subarrays
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = i; j < arr.size(); j++)
    {

      // calculate sum for subarray [i...j]
      int sum = 0;
      for (int t = i; t <= j; t++)
      {
        sum += arr[t];
      }

      // check condition
      if (sum == k)
      {
        len = max(len, j - i + 1);
      }
    }
  }

  return len;
}

// ----------------------------------------------------------------------------
// 🟡 2. BRUTE OPTIMIZED (O(n^2))
// ----------------------------------------------------------------------------
int longestSubarrayWithSum_BRUTE_optimized(vector<int> arr, int k)
{
  int len = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    int sum = 0; // reset sum for new starting point

    for (int j = i; j < arr.size(); j++)
    {

      // instead of recalculating sum, keep adding
      sum += arr[j];

      if (sum == k)
      {
        len = max(len, j - i + 1);
      }
    }
  }

  return len;
}

/*
================================================================================
🟢 3. PREFIX SUM + HASHMAP (BEST GENERAL SOLUTION)

👉 Works for:
✔ positive numbers
✔ negative numbers
✔ zeroes

--------------------------------------------------------------------------------
🧠 IDEA:

prefix sum = sum of elements from index 0 to i

If:
    prefixSum[i] - prefixSum[j] = k

Then:
    subarray (j+1 → i) has sum k

So we check:
    rem = current_sum - k

If rem exists in map → we found a subarray
================================================================================
*/

int longestSubarrayWithSum_BETTER(vector<int> arr, int k)
{
  unordered_map<long long, int> preSumMap;

  long long sum = 0;
  int maxLen = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    sum += arr[i];

    // case 1: subarray from 0 → i
    if (sum == k)
    {
      maxLen = max(maxLen, i + 1);
    }

    // case 2: subarray in middle
    long long rem = sum - k;

    if (preSumMap.find(rem) != preSumMap.end())
    {
      int len = i - preSumMap[rem];
      maxLen = max(maxLen, len);
    }

    /*
    ⚠️ IMPORTANT:

    👉 Store ONLY first occurrence of prefix sum
    👉 Why? To maximize length of subarray

    ❌ Wrong:
        preSumMap[sum] = i;  // overwrites

    ✅ Correct:
    */
    if (preSumMap.find(sum) == preSumMap.end())
    {
      preSumMap[sum] = i;
    }
  }

  return maxLen;
}

/*
================================================================================
🔵 4. SLIDING WINDOW (OPTIMAL FOR POSITIVES)

👉 Works ONLY when:
✔ all elements are positive (or zero)

❌ Fails when:
✘ negative numbers present

--------------------------------------------------------------------------------
🧠 IDEA:

Expand window → increase sum
Shrink window → decrease sum

Because all elements are positive:
→ sum always increases when expanding
→ sum always decreases when shrinking
================================================================================
*/

int longestSubarrayWithSum_Optimal(vector<int> arr, int k)
{
  int left = 0, right = 0;
  long long sum = 0;
  int maxLen = 0;

  int n = arr.size();

  while (right < n)
  {

    // expand window
    sum += arr[right];

    // shrink window if sum > k
    while (left <= right && sum > k)
    {
      sum -= arr[left];
      left++;
    }

    // check condition
    if (sum == k)
    {
      maxLen = max(maxLen, right - left + 1);
    }

    right++;
  }

  return maxLen;
}

/*
================================================================================
🎯 INTERVIEW SUMMARY:

👉 If array has ONLY positives:
    → Use Sliding Window (O(n), best)

👉 If array has negatives/zero:
    → Use Prefix Sum + HashMap (O(n), safest)

👉 Always mention both approaches in interview!
================================================================================
*/

int main()
{
  vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
  int k = 4;

  cout << "BRUTE: " << longestSubarrayWithSum_BRUTE(arr, k) << endl;
  cout << "BRUTE OPTIMIZED: " << longestSubarrayWithSum_BRUTE_optimized(arr, k) << endl;
  cout << "BETTER (HASHMAP): " << longestSubarrayWithSum_BETTER(arr, k) << endl;
  cout << "OPTIMAL (SLIDING WINDOW): " << longestSubarrayWithSum_Optimal(arr, k) << endl;

  return 0;
}
