#include <algorithm>
#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
  for (auto element : arr) {
    std::cout << element << " ";
  }
  std::cout << '\n';
}

/*
    Partitioning Procedure
    ----------------------

    1. i = low + 1
    2. j = high
    3. pivot = arr[low]
    4. Increment i until arr[i] > pivot
    5. Decrement j until arr[j] <= pivot
    6. Swap arr[i] and arr[j] while i < j
    7. Swap pivot with arr[j]
    8. Return j (final position of pivot)
*/

int partition(std::vector<int>& arr, int low, int high) {
  int pivot = arr[low];

  int i = low + 1;
  int j = high;

  do {
    while (i <= high && arr[i] <= pivot) {
      i++;
    }

    while (arr[j] > pivot) {
      j--;
    }

    if (i < j) {
      std::swap(arr[i], arr[j]);
    }

  } while (i < j);

  std::swap(arr[low], arr[j]);

  return j;
}

void quickSort(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    int partitionIndex = partition(arr, low, high);

    // Sort left subarray
    quickSort(arr, low, partitionIndex - 1);

    // Sort right subarray
    quickSort(arr, partitionIndex + 1, high);
  }
}

int main() {
  std::vector<int> arr = {1, 3, 6, 2, 4, 5, 9, 8, 7};

  std::cout << "Array before: ";
  printArray(arr);

  std::cout << "Performing quick sort...\n";

  quickSort(arr, 0, arr.size() - 1);

  std::cout << "Array after: ";
  printArray(arr);

  return 0;
}
