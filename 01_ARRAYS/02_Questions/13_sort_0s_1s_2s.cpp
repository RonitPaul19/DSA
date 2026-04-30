// Sort an array of 0's, 1's and 2's
#include <bits/stdc++.h>
using namespace std;

/*
==============================================================================
🧠 THEORY:

👉 This problem is based on:
   "3-way partitioning"

👉 Also known as:
   Dutch National Flag Algorithm

👉 Core Idea:
We divide the array into 4 regions:

[0 ... low-1]       → all 0s
[low ... mid-1]     → all 1s
[mid ... high]      → UNKNOWN
[high+1 ... n-1]    → all 2s

👉 Goal:
Shrink the UNKNOWN region [mid ... high]

==============================================================================
📊 GRAPHICAL REPRESENTATION:

Initial:
[ ? ? ? ? ? ? ? ]
  L M         H

After some steps:
[ 0 0 | 1 1 | ? ? ? | 2 2 ]
        L   M       H

Final:
[ 0 0 1 1 1 2 2 ]
              (mid > high → DONE)

==============================================================================
*/

// ---------------------------------------------------------------------------
// 🟡 BETTER SOLUTION (COUNTING)
// ---------------------------------------------------------------------------
/*
👉 TC = O(n)
👉 SC = O(1)

IDEA:
- Count number of 0s and 1s
- Fill array accordingly

[0 ... zeros-1]          → 0s
[zeros ... zeros+ones-1] → 1s
[zeros+ones ... n-1]     → 2s
*/
void SORT_BETTER(vector<int>& arr) {
  int n = arr.size();
  int zeros = 0, ones = 0;

  // Count
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0)
      zeros++;
    else if (arr[i] == 1)
      ones++;
  }

  // Fill 0s
  for (int i = 0; i <= zeros - 1; i++) arr[i] = 0;

  // Fill 1s
  for (int i = zeros; i <= zeros + ones - 1; i++) arr[i] = 1;

  // Fill 2s
  for (int i = zeros + ones; i < n; i++) arr[i] = 2;
}

// ---------------------------------------------------------------------------
// 🟢 OPTIMAL SOLUTION (DNF - ONE PASS)
// ---------------------------------------------------------------------------
/*
👉 TC = O(n)
👉 SC = O(1)

------------------------------------------------------------------------------
🧠 LOGIC:

CASE 1: arr[mid] == 0
→ belongs to front
→ swap(mid, low)
→ low++, mid++

CASE 2: arr[mid] == 1
→ already correct
→ mid++

CASE 3: arr[mid] == 2
→ belongs to end
→ swap(mid, high)
→ high--
→ ❗ DO NOT move mid

-------------------------------------------------------------------------------
🔥 KEY INSIGHT:

When swapping with HIGH,
the incoming element is UNKNOWN,
so we must re-check it.

==============================================================================
*/
void SORT_OPTIMAL(vector<int>& arr) {
  int low = 0, mid = 0, high = arr.size() - 1;

  while (mid <= high) {
    if (arr[mid] == 0) {
      swap(arr[mid], arr[low]);
      low++;
      mid++;
    } else if (arr[mid] == 1) {
      mid++;
    } else {  // arr[mid] == 2
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}

/*
===============================================================================
🎯 INTERVIEW SUMMARY:

1. BRUTE → sort() → O(n log n)

2. BETTER → counting → O(n)

3. OPTIMAL → DNF → O(n) (single pass)

👉 Best answer:
   Dutch National Flag Algorithm

===============================================================================
*/

/*
/*
===============================================================================
EXAMPLE DRY RUN
===============================================================================

arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0}

low = 0, mid = 0, high = 10

-------------------------------------------------------------------------------

1. {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0}
   low = 0, mid = 0, high = 10
   a[mid] == 0  --> swap(a[low], a[mid])
   low++, mid++

   {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0}
   low = 1, mid = 1, high = 10

-------------------------------------------------------------------------------

2. {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0}
   low = 1, mid = 1, high = 10
   a[mid] == 1  --> mid++

   low = 1, mid = 2, high = 10

-------------------------------------------------------------------------------

3. {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0}
   low = 1, mid = 2, high = 10
   a[mid] == 1  --> mid++

   low = 1, mid = 3, high = 10

-------------------------------------------------------------------------------

4. {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0}
   low = 1, mid = 3, high = 10
   a[mid] == 0  --> swap(a[low], a[mid])

   {0, 0, 1, 1, 1, 2, 1, 2, 0, 0, 0}
   low = 2, mid = 4, high = 10

-------------------------------------------------------------------------------

5. {0, 0, 1, 1, 1, 2, 1, 2, 0, 0, 0}
   low = 2, mid = 4, high = 10
   a[mid] == 1  --> mid++

   low = 2, mid = 5, high = 10

-------------------------------------------------------------------------------

6. {0, 0, 1, 1, 1, 2, 1, 2, 0, 0, 0}
   low = 2, mid = 5, high = 10
   a[mid] == 2  --> swap(a[mid], a[high])

   {0, 0, 1, 1, 1, 0, 1, 2, 0, 0, 2}
   low = 2, mid = 5, high = 9

-------------------------------------------------------------------------------

7. {0, 0, 1, 1, 1, 0, 1, 2, 0, 0, 2}
   low = 2, mid = 5, high = 9
   a[mid] == 0  --> swap(a[low], a[mid])

   {0, 0, 0, 1, 1, 1, 1, 2, 0, 0, 2}
   low = 3, mid = 6, high = 9

-------------------------------------------------------------------------------

8. {0, 0, 0, 1, 1, 1, 1, 2, 0, 0, 2}
   low = 3, mid = 6, high = 9
   a[mid] == 1  --> mid++

   low = 3, mid = 7, high = 9

-------------------------------------------------------------------------------

9. {0, 0, 0, 1, 1, 1, 1, 2, 0, 0, 2}
   low = 3, mid = 7, high = 9
   a[mid] == 2  --> swap(a[mid], a[high])

   {0, 0, 0, 1, 1, 1, 1, 0, 0, 2, 2}
   low = 3, mid = 7, high = 8

-------------------------------------------------------------------------------

10. {0, 0, 0, 1, 1, 1, 1, 0, 0, 2, 2}
    low = 3, mid = 7, high = 8
    a[mid] == 0  --> swap(a[low], a[mid])

    {0, 0, 0, 0, 1, 1, 1, 1, 0, 2, 2}
    low = 4, mid = 8, high = 8

-------------------------------------------------------------------------------

11. {0, 0, 0, 0, 1, 1, 1, 1, 0, 2, 2}
    low = 4, mid = 8, high = 8
    a[mid] == 0  --> swap(a[low], a[mid])

    {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2}
    low = 5, mid = 9, high = 8

-------------------------------------------------------------------------------

STOP (mid > high)

FINAL ARRAY:
{0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2}

===============================================================================
*/

// ----------------------------------------------------------------------------
// 🧪 TEST CASES
// ----------------------------------------------------------------------------
void print(vector<int>& arr) {
  for (auto x : arr) cout << x << " ";
  cout << endl;
}

int main() {
  vector<int> arr1 = {2, 0, 2, 1, 1, 0};
  vector<int> arr2 = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
  vector<int> arr3 = {2, 2, 2, 2};
  vector<int> arr4 = {0, 0, 0, 0};
  vector<int> arr5 = {1, 1, 1, 1};

  cout << "Original:\n";
  print(arr2);

  SORT_OPTIMAL(arr2);

  cout << "Sorted (Optimal):\n";
  print(arr2);

  cout << "\nMore Tests:\n";

  SORT_OPTIMAL(arr1);
  print(arr1);

  SORT_OPTIMAL(arr3);
  print(arr3);

  SORT_OPTIMAL(arr4);
  print(arr4);

  SORT_OPTIMAL(arr5);
  print(arr5);

  return 0;
}
