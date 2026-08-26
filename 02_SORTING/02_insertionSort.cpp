#include <iostream>
#include <utility>
#include <vector>

void printArray(std::vector<int>& arr) {
  for (auto elements : arr) {
    std::cout << elements << " ";
  }
  std::cout << std::endl;
}

// BUBBLE SORT

/*

1st pass:
[ 7 | 12 3 4 1 ] -> insert 12
[ 7 12 | 3 4 1 ]

2nd pass:
[ 7 12 | 3 4 1 ] -> Insert 3
[ 3 7 12 | 4 1 ]

3rd pass:
[ 3 7 12 | 4 1 ] -> insert 4
[ 3 4 7 12 | 1 ]

4th pass:
[ 3 4 7 12 | 1 ] -> insert 1
[ 1 3 4 7 12 | ]

(* No elements left in the right of the bar so all elements are sorted *)

*/

void insertionSort(std::vector<int>& arr) {
  int n = arr.size();
  int key, j;

  // loop for PASSES
  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    // loop for each pass
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

int main() {
  std::vector<int> arr = {1, 3, 6, 2, 4, 5, 9, 8, 7};

  std::cout << "Array before bubble sort : ";
  printArray(arr);

  std::cout << "Preforming insertion sort...\n";
  insertionSort(arr);

  std::cout << "Array after bubble sort : ";
  printArray(arr);

  return 0;
}
