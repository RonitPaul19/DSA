#include <iostream>
using namespace std;

struct myArray {
  int total_size;
  int used_size;
  int* ptr;
};

void createArray(struct myArray* a, int tSize, int uSize) {
  a->total_size = tSize;
  a->used_size = uSize;
  a->ptr = new int[tSize];
}

void show(struct myArray* a) {
  for (int i = 0; i < a->used_size; i++) {
    cout << (a->ptr)[i] << " ";
  }
}

int main() {
  struct myArray marks;

  int tSize = 10;
  int uSize = 2;

  createArray(&marks, tSize, uSize);

  show(&marks);

  return 0;
}
