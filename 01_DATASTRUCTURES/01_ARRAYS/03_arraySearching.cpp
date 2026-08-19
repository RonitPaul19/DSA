#include <iostream>
using namespace std;

class Search {
 private:
  int* arr;
  int size;

 public:
  // Constructor
  Search(int arr[], int size) {
    this->arr = arr;
    this->size = size;
  }

  // Linear Search
  int linearSearch(int element) {
    for (int i = 0; i < size; i++) {
      if (arr[i] == element) {
        return i;
      }
    }

    return -1;
  }

  // Binary Search
  int binarySearch(int element) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (arr[mid] == element) {
        return mid;
      }

      if (arr[mid] < element) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return -1;
  }
};

int main() {
  int arr[] = {10, 20, 30, 40, 50, 60, 70};
  int size = 7;

  Search search(arr, size);

  int element = 40;

  // Linear Search
  int linearResult = search.linearSearch(element);

  if (linearResult != -1) {
    cout << "Linear Search: Element found at index " << linearResult << '\n';
  } else {
    cout << "Linear Search: Element not found\n";
  }

  // Binary Search
  int binaryResult = search.binarySearch(element);

  if (binaryResult != -1) {
    cout << "Binary Search: Element found at index " << binaryResult << '\n';
  } else {
    cout << "Binary Search: Element not found\n";
  }

  return 0;
}
