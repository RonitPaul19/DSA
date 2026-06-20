#include <bits/stdc++.h>
using namespace std;

int insertion(int a[], int n, int max, int el, int index) {
  if (n >= max)
    return -1;
  else {
    for (int i = n; i >= index; i++) a[i + 1] = a[i];
    a[index] = el;
    return 1;
  }
}

int main() {
  int max, n;
  cout << "Enter the maximum size of the array : ";
  cin >> max;
  cout << "Enter the initial size of the array : ";
  cin >> n;
  int arr[max];

  cout << "Enter the elements of the initial array : ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int el, i;
  cout << "Enter the element you want to store in the array : ";
  cin >> el;
  cout << "Enter the index in which you want to store : ";
  cin >> i;

  int result = insertion(arr, n, max, el, i);
  if (result) {
    cout << "Insertion successfull ! ";
    n++;
  } else
    cout << "Insertion operation failed !!";

  cout << "\n";

  cout << "Final array : ";
  for (int i = 0; i < n; i++) {
    cout << arr[i];
  }

  return 0;
}
