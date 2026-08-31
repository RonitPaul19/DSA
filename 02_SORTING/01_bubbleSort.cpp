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
void bubbleSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// BUBBLE SORT ADAPTIVE
void bubbleSortAdaptive(std::vector<int>& arr) {
  int n = arr.size();
  bool isSorted = false;
  for (int i = 0; i < n - 1; i++) {
    isSorted = true;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        isSorted = false;
      }
    }
    if (isSorted) {
      return;
    }
  }
}

int main() {
  std::vector<int> arr = {1, 3, 6, 2, 4, 5, 9, 8, 7};

  std::cout << "Array before : ";
  printArray(arr);

  std::cout << "Preforming bubble sort...\n";
  bubbleSort(arr);

  std::cout << "Array after : ";
  printArray(arr);

  return 0;
}
