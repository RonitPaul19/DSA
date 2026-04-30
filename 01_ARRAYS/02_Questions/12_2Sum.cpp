// PROBLEM: 2 Sum
// Given an array and a target, find if there exist two numbers such that:
//      arr[i] + arr[j] = target

// VARIETY 1:
// Return TRUE / FALSE

// VARIETY 2:
// Return INDICES of the two numbers

#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
🧠 THEORY:

👉 Core idea:
For every element 'a', we need another element:
    target - a

👉 This is called:
    "complement approach"

===============================================================================
*/

// ----------------------------------------------------------------------------
// 🔴 1. BRUTE FORCE (O(n^2))
// ----------------------------------------------------------------------------
bool TwoSum_variety1_BRUTE(const vector<int>& arr, int target) {
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] + arr[j] == target) {
        return true;
      }
    }
  }

  return false;
}

/*
===============================================================================
🟡 2. BETTER (HASHING)

👉 TC = O(n log n) using map
👉 TC = O(n) using unordered_map

-------------------------------------------------------------------------------
🧠 IDEA:

While traversing:
- Check if complement already exists
- If yes → answer found
- Else → store current element

===============================================================================
*/

bool TwoSum_variety1_BETTER(const vector<int>& arr, int target) {
  unordered_map<int, int> mpp;  // value → index

  for (int i = 0; i < arr.size(); i++) {
    int a = arr[i];
    int more = target - a;

    // check if complement already seen
    if (mpp.find(more) != mpp.end()) {
      return true;
    }

    // store current element
    mpp[a] = i;
  }

  return false;
}

/*
===============================================================================
🟡 VARIETY 2 (RETURN INDICES)

👉 Same logic, just return indices instead of boolean

⚠️ IMPORTANT:
- Works even if duplicates exist
- Order matters → don't sort

===============================================================================
*/

pair<int, int> TwoSum_variety2_BETTER(const vector<int>& arr, int target) {
  unordered_map<int, int> mpp;

  for (int i = 0; i < arr.size(); i++) {
    int more = target - arr[i];

    if (mpp.find(more) != mpp.end()) {
      return {mpp[more], i};
    }

    mpp[arr[i]] = i;
  }

  return {-1, -1};  // if not found
}

/*
===============================================================================
🟢 3. OPTIMAL (TWO POINTER)

👉 TC = O(n log n) (due to sorting)
👉 SC = O(1)

-------------------------------------------------------------------------------
🧠 IDEA:

- Sort array
- Use two pointers:
    left → smallest
    right → largest

- Adjust based on sum

===============================================================================
*/

bool TwoSum_variety1_OPTIMAL(vector<int> arr, int target) {
  // ⚠️ We sort → original indices LOST
  sort(arr.begin(), arr.end());

  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];

    if (sum < target) {
      left++;
    } else if (sum > target) {
      right--;
    } else {
      return true;
    }
  }

  return false;
}

/*
===============================================================================
⚠️ VERY IMPORTANT POINTS:

1. HASHMAP APPROACH:
   ✔ Best for returning indices
   ✔ Works for unsorted arrays
   ✔ Works with duplicates

2. TWO POINTER APPROACH:
   ✔ Only for checking existence
   ✔ Requires sorted array
   ❌ Cannot return original indices directly

3. Always clarify in interview:
   👉 "Do you want indices or just existence?"

===============================================================================
*/

/*
===============================================================================
🎯 INTERVIEW SUMMARY (FINAL)

1. If asked for BEST TIME COMPLEXITY:
   → Use HASHING (O(n))

2. If asked for O(1) SPACE:
   → Use TWO POINTER (after sorting)

3. If asked for INDICES:
   → ONLY HASHING works directly

4. If array is ALREADY SORTED:
   → TWO POINTER is best

5. Always clarify:
   → "Do we need indices or just existence?"

===============================================================================
*/

int main() {
  vector<int> arr = {2, 6, 5, 8, 11};
  int target = 14;

  cout << "BRUTE: " << TwoSum_variety1_BRUTE(arr, target) << endl;
  cout << "BETTER: " << TwoSum_variety1_BETTER(arr, target) << endl;
  cout << "OPTIMAL: " << TwoSum_variety1_OPTIMAL(arr, target) << endl;

  auto p = TwoSum_variety2_BETTER(arr, target);
  cout << "INDICES: " << p.first << ", " << p.second << endl;

  return 0;
}
