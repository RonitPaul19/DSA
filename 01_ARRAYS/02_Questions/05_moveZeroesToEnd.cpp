// PROBLEM:
// Move all zeroes to the end of the array while maintaining the relative order
// of non-zero elements.

// NOTE:
// - Do it IN-PLACE for optimal solution
// - Order of non-zero elements must remain same

#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
🧠 THEORY:

👉 Key idea:
We need to "shift all non-zero elements to front"
and "push zeroes to the back"

👉 Order matters → so we CANNOT sort

👉 This is a STABLE rearrangement problem

===============================================================================
*/

// ----------------------------------------------------------------------------
// 🔴 1. BRUTE FORCE
// ----------------------------------------------------------------------------
void moveAllZeroesToEnd_BRUTE(vector<int>& a) {
  /*
  IDEA:
  - Store all non-zero elements in a temporary array
  - Copy them back
  - Fill remaining positions with zeroes
  */

  vector<int> temp;

  // store non-zero elements → O(n)
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != 0) {
      temp.push_back(a[i]);
    }
  }

  // copy back → O(n)
  for (int i = 0; i < temp.size(); i++) {
    a[i] = temp[i];
  }

  // fill rest with zeroes → O(n)
  for (int i = temp.size(); i < a.size(); i++) {
    a[i] = 0;
  }

  /*
  TC = O(2n) ~ O(n)
  SC = O(x)  (x = number of non-zero elements)
  */
}

/*
===============================================================================
🟢 2. OPTIMAL (TWO POINTER)

👉 TC = O(n)
👉 SC = O(1)

-------------------------------------------------------------------------------
🧠 IDEA:

Step 1: Find first zero index (j)
Step 2: Traverse ahead (i)
Step 3: Whenever non-zero found → swap with j → increment j

👉 This ensures:
- non-zero elements move forward
- zeroes automatically shift backward

===============================================================================
*/

void moveAllZeroesToEnd_OPTIMAL(vector<int>& a) {
  int j = -1;

  // Step 1: Find first zero
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 0) {
      j = i;
      break;
    }
  }

  // ⚠️ EDGE CASE: If no zero found → array already valid
  if (j == -1) return;

  // Step 2: Traverse remaining array
  for (int i = j + 1; i < a.size(); i++) {
    // If non-zero found → swap with zero position
    if (a[i] != 0) {
      swap(a[i], a[j]);

      // Move j forward to next zero position
      j++;
    }
  }
}

/*
===============================================================================
🎯 DRY RUN:

a = [1, 0, 2, 0, 3]

j = index of first zero = 1

i = 2 → 2 != 0 → swap → [1, 2, 0, 0, 3], j = 2
i = 3 → skip
i = 4 → 3 != 0 → swap → [1, 2, 3, 0, 0], j = 3

===============================================================================
*/

/*
===============================================================================
⚠️ IMPORTANT POINTS:

1. Maintain order → don't use sorting

2. j always points to:
   👉 "position where next non-zero should go"

3. After swap:
   👉 j++ (very important)

4. Works for:
   ✔ positives
   ✔ negatives
   ✔ zeroes

===============================================================================
*/

/*
===============================================================================
🎯 INTERVIEW SUMMARY:

👉 If extra space allowed:
    → use temp array (easy)

👉 If in-place required:
    → use 2-pointer (optimal)

👉 Always mention:
    "We maintain relative order, so stable shifting is needed"

===============================================================================
*/

int main() {
  vector<int> a = {1, 0, 2, 0, 3, 0, 4, 0, 5, 6};

  cout << "Before: ";
  for (auto it : a) cout << it << " ";

  // moveAllZeroesToEnd_BRUTE(a);
  moveAllZeroesToEnd_OPTIMAL(a);

  cout << "\nAfter: ";
  for (auto it : a) cout << it << " ";

  return 0;
}
