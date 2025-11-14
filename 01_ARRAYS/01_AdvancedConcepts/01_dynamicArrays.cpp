#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n]; // dynamic array

    // input elements
    for(int i=0; i<n; i++) cin >> arr[i];

    // print elements
    for(int i=0; i<n; i++) cout << arr[i] << " ";

    delete[] arr; // free memory
    return 0;
}
