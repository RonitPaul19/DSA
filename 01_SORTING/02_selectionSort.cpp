#include <algorithm>
#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int mini = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }

    swap(arr[i], arr[mini]);
  }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original array:\n";
  printArray(arr, n);

  selectionSort(arr, n);

  cout << "Sorted array:\n";
  printArray(arr, n);

  return 0;
}
