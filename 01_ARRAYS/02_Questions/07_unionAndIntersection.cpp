// PROBLEM:
// Given two SORTED arrays, find:
// 1. UNION → all unique elements from both arrays
// 2. INTERSECTION → common elements

// NOTE:
// Arrays are SORTED → this is the key advantage

#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
🧠 THEORY:

👉 Sorted arrays → we can use TWO POINTER technique

👉 Similar to MERGE step in Merge Sort

👉 Key challenge:
- Handling duplicates correctly

===============================================================================
*/

// ----------------------------------------------------------------------------
// 🔴 1. UNION (BRUTE USING SET)
// ----------------------------------------------------------------------------
vector<int> findUnion_BRUTE(vector<int> a1, vector<int> a2) {
  /*
  IDEA:
  - Insert all elements into a set
  - Set automatically removes duplicates and keeps sorted order
  */

  set<int> st;

  for (auto it : a1) st.insert(it);
  for (auto it : a2) st.insert(it);

  /*
  TC = O((n + m) log(n + m))
  SC = O(n + m)
  */

  return vector<int>(st.begin(), st.end());
}

/*
===============================================================================
🟢 2. UNION (OPTIMAL - TWO POINTER)

👉 TC = O(n + m)
👉 SC = O(n + m) (for result)

-------------------------------------------------------------------------------
🧠 IDEA:

- Traverse both arrays simultaneously
- Always take the smaller element
- Avoid duplicates using:
    ans.back() != current element

===============================================================================
*/

vector<int> findUnion_OPTIMAL(vector<int> a1, vector<int> a2) {
  int i = 0, j = 0;
  vector<int> ans;

  while (i < a1.size() && j < a2.size()) {
    if (a1[i] <= a2[j]) {
      /*
      Take from a1 if smaller or equal
      */
      if (ans.empty() || ans.back() != a1[i]) {
        ans.push_back(a1[i]);
      }
      i++;

    } else {
      /*
      Take from a2
      */
      if (ans.empty() || ans.back() != a2[j]) {
        ans.push_back(a2[j]);
      }
      j++;
    }
  }

  /*
  Add remaining elements (very important)
  */

  while (i < a1.size()) {
    if (ans.empty() || ans.back() != a1[i]) {
      ans.push_back(a1[i]);
    }
    i++;
  }

  while (j < a2.size()) {
    if (ans.empty() || ans.back() != a2[j]) {
      ans.push_back(a2[j]);
    }
    j++;
  }

  return ans;
}

/*
===============================================================================
🔵 INTERSECTION

👉 Only common elements

Two variations:
1. UNIQUE intersection (no duplicates)
2. COUNT-based (duplicates allowed)

===============================================================================
*/

// ----------------------------------------------------------------------------
// 🔴 3. INTERSECTION (BRUTE)
// ----------------------------------------------------------------------------
vector<int> findIntersection_BRUTE(vector<int> a1, vector<int> a2) {
  vector<int> ans;

  for (int i = 0; i < a1.size(); i++) {
    for (int j = 0; j < a2.size(); j++) {
      if (a1[i] == a2[j]) {
        /*
        Avoid duplicates in result
        */
        if (ans.empty() || ans.back() != a1[i]) {
          ans.push_back(a1[i]);
        }

        break;  // prevent multiple matches
      }
    }
  }

  return ans;
}

/*
===============================================================================
🟢 4. INTERSECTION (OPTIMAL - UNIQUE)

👉 TC = O(n + m)

-------------------------------------------------------------------------------
🧠 IDEA:

- Same as merge
- If equal → add once and move both pointers
- Skip duplicates using ans.back()

===============================================================================
*/

vector<int> findIntersection_OPTIMAL_UNIQUE(vector<int> a, vector<int> b) {
  int i = 0, j = 0;
  vector<int> ans;

  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) {
      i++;
    } else if (b[j] < a[i]) {
      j++;
    } else {
      /*
      Found common element
      */
      if (ans.empty() || ans.back() != a[i]) {
        ans.push_back(a[i]);
      }

      i++;
      j++;
    }
  }

  return ans;
}

/*
===============================================================================
🟢 5. INTERSECTION (OPTIMAL - COUNT BASED)

👉 Includes duplicates

Example:
a = [1,2,2,3]
b = [2,2,4]

Result = [2,2]

===============================================================================
*/

vector<int> findIntersection_OPTIMAL_COUNT(vector<int> a, vector<int> b) {
  int i = 0, j = 0;
  vector<int> ans;

  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) {
      i++;
    } else if (b[j] < a[i]) {
      j++;
    } else {
      /*
      Add ALL matches (no duplicate restriction)
      */
      ans.push_back(a[i]);

      i++;
      j++;
    }
  }

  return ans;
}

/*
===============================================================================
⚠️ IMPORTANT OBSERVATIONS:

1. Sorted property is EVERYTHING here
   → enables O(n + m) solution

2. UNION:
   - Avoid duplicates → check ans.back()

3. INTERSECTION:
   - UNIQUE → avoid duplicates
   - COUNT → allow duplicates

4. This is similar to:
   👉 Merge step in Merge Sort

===============================================================================
*/

/*
===============================================================================
🎯 INTERVIEW SUMMARY:

👉 If arrays are sorted:
    → Always use 2-pointer (best)

👉 If NOT sorted:
    → Use set or hashmap

👉 Always mention:
    "Since arrays are sorted, we can merge in linear time"

===============================================================================
*/

int main() {
  vector<int> a1 = {1, 1, 2, 3, 4, 5};
  vector<int> a2 = {2, 3, 4, 4, 5};

  vector<int> U = findUnion_OPTIMAL(a1, a2);
  vector<int> I_unique = findIntersection_OPTIMAL_UNIQUE(a1, a2);
  vector<int> I_count = findIntersection_OPTIMAL_COUNT(a1, a2);

  cout << "UNION: ";
  for (auto it : U) cout << it << " ";

  cout << "\nINTERSECTION (UNIQUE): ";
  for (auto it : I_unique) cout << it << " ";

  cout << "\nINTERSECTION (COUNT): ";
  for (auto it : I_count) cout << it << " ";

  return 0;
}
