#include <iostream>
#include <utility>
#include <vector>

void printArray(std::vector<int>& arr) {
  for (auto elements : arr) {
    std::cout << elements << " ";
  }
  std::cout << std::endl;
}

//                          Selection sort
//                          --------------
// concept - select the minimum element and put it in the front and find the min
//           element in the remaining array and fill all the places likewise

void selectionSort(std::vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i; j < arr.size(); j++) {
      if (arr[j] < arr[i]) {
        std::swap(arr[i], arr[j]);
      }
    }
  }
}

int main() {
  std::vector<int> arr = {1, 3, 6, 2, 4, 5, 9, 8, 7};

  std::cout << "Array before bubble sort : ";
  printArray(arr);

  std::cout << "Preforming insertion sort...\n";
  selectionSort(arr);

  std::cout << "Array after bubble sort : ";
  printArray(arr);

  return 0;
}
