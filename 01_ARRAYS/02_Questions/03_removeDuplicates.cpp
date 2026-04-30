// PROBLEM:
// Given a SORTED array, remove duplicates IN-PLACE
// and return the number of unique elements.

// NOTE:
// - Order must be maintained
// - Do NOT use extra space in optimal solution
// - Return length of unique part (not full array)

#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
🧠 THEORY:

👉 Key observation:
Array is SORTED → duplicates are always ADJACENT

Example:
1 2 2 3 3 4 4 5

👉 So we don't need hashing or extra DS
👉 Just compare with previous element

===============================================================================
*/

// ----------------------------------------------------------------------------
// 🔴 1. BRUTE FORCE (USING SET)
// ----------------------------------------------------------------------------
int removeDuplicates_BRUTE(vector<int>& arr) {
  /*
  IDEA:
  - Insert all elements into a set
  - Set stores only unique elements (automatically removes duplicates)
  */

  set<int> st;

  // O(n log n)
  for (int i = 0; i < arr.size(); i++) {
    st.insert(arr[i]);
  }

  /*
  ⚠️ NOTE:
  - set keeps elements sorted
  - but we are already given sorted array
  - still works but unnecessary overhead
  */

  // copy back to array → O(n)
  int index = 0;
  for (auto it : st) {
    arr[index] = it;
    index++;
  }

  return st.size();  // number of unique elements
}

/*
===============================================================================
🟢 2. OPTIMAL (TWO POINTER APPROACH)

👉 TC = O(n)
👉 SC = O(1)

-------------------------------------------------------------------------------
🧠 IDEA:

We maintain two pointers:

i → points to last UNIQUE element
j → traverses the array

If arr[j] != arr[i]:
    → we found a new unique element
    → move it to position i+1

===============================================================================
*/

int removeDuplicates_OPTIMAL(vector<int>& arr) {
  /*
  ⚠️ EDGE CASE:
  If array is empty
  */
  if (arr.size() == 0) return 0;

  int i = 0;  // points to last unique element

  for (int j = 1; j < arr.size(); j++) {
    /*
    Compare current element with last unique element
    */
    if (arr[j] != arr[i]) {
      /*
      Found new unique element
      Place it next to last unique position
      */
      arr[i + 1] = arr[j];

      i++;  // expand unique section
    }
  }

  /*
  Final size = index of last unique + 1
  */
  return (i + 1);
}

/*
===============================================================================
🎯 DRY RUN:

arr = [1, 2, 2, 3, 3]

i = 0

j = 1 → arr[j] != arr[i] → place at i+1 → i = 1
j = 2 → same → skip
j = 3 → new → place at i+1 → i = 2

Final array:
[1, 2, 3, ...]

Return = 3

===============================================================================
*/

/*
===============================================================================
⚠️ IMPORTANT POINTS / PITFALLS:

1. Works ONLY because array is SORTED
   ❌ If unsorted → this approach fails

2. We are NOT deleting elements
   → Just overwriting front part

3. Elements after returned length are garbage → IGNORE them

4. Always return (i + 1), NOT i

===============================================================================
*/

/*
===============================================================================
🎯 INTERVIEW SUMMARY:

👉 If sorted array:
    → Use Two Pointer (best)

👉 If NOT sorted:
    → Use set or hashmap

👉 Always mention:
    "Since array is sorted, duplicates are adjacent"

===============================================================================
*/

int main() {
  vector<int> arr = {1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7};

  cout << "Before: ";
  for (auto it : arr) cout << it << " ";

  int newSize = removeDuplicates_OPTIMAL(arr);

  cout << "\nAfter: ";
  for (int i = 0; i < newSize; i++) {
    cout << arr[i] << " ";  // print only valid part
  }

  cout << "\nSize of unique elements: " << newSize << endl;

  return 0;
}
