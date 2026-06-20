#include <bits/stdc++.h>
using namespace std;

int insertion(int a[], int n, int maxSize, int el, int index) {
  if (n >= maxSize || index > n || index < 0) return -1;

  for (int i = n - 1; i >= index; i--) {
    a[i + 1] = a[i];
  }

  a[index] = el;
  return 1;
}

int deletion(int a[], int n, int index) {
  if (index >= n || index < 0) return -1;

  for (int i = index; i < n - 1; i++) {
    a[i] = a[i + 1];
  }

  return 1;
}

int main() {
  int maxSize, n;

  cout << "Enter max size: ";
  cin >> maxSize;

  cout << "Enter current size: ";
  cin >> n;

  int arr[maxSize];

  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int el, idx;

  cout << "Enter element and index for insertion: ";
  cin >> el >> idx;

  if (insertion(arr, n, maxSize, el, idx)) {
    n++;
    cout << "Insertion successful\n";
  } else {
    cout << "Insertion failed\n";
  }

  cout << "Array after insertion: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << "\nEnter index to delete: ";
  cin >> idx;

  if (deletion(arr, n, idx)) {
    n--;
    cout << "Deletion successful\n";
  } else {
    cout << "Deletion failed\n";
  }

  cout << "Final array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
