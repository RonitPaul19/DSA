#include <iostream>
using namespace std;

class Array {
private:
  int* arr;
  int size;
  int capacity;

public:
  // Constructor
  Array(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new int[capacity];
  }

  // Destructor
  ~Array() {
    delete[] arr;
  }

  // Traversal
  void display() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << '\n';
  }

  // Insertion
  bool indInsertion(int element, int index) {
    if (size >= capacity || index < 0 || index > size) {
      return false;
    }

    for (int i = size - 1; i >= index; i--) {
      arr[i + 1] = arr[i];
    }

    arr[index] = element;
    size++;

    return true;
  }

  // Deletion
  bool indDeletion(int index) {
    if (index < 0 || index >= size) {
      return false;
    }

    for (int i = index; i < size - 1; i++) {
      arr[i] = arr[i + 1];
    }

    size--;

    return true;
  }
};

int main() {
  Array arr(100);

  // Insertion
  arr.indInsertion(1, 0);
  arr.indInsertion(2, 1);
  arr.indInsertion(5, 2);
  arr.indInsertion(8, 3);

  arr.display();

  // Insert 45 at index 3
  if (arr.indInsertion(45, 3)) {
    cout << "Insertion Successful!\n";
  } else {
    cout << "Insertion Unsuccessful!\n";
  }

  arr.display();

  // Delete element at index 2
  if (arr.indDeletion(2)) {
    cout << "Deletion Successful!\n";
  } else {
    cout << "Deletion Unsuccessful!\n";
  }

  arr.display();

  return 0;
}
