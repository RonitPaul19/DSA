#include <iostream>

struct stack {
  int size;
  int top;
  int* arr;
};

bool isEmpty(struct stack* ptr) {
  if (ptr->top == -1) {
    return true;
  } else {
    return false;
  }
}

bool isFull(struct stack* ptr) {
  if (ptr->top == ptr->size - 1) {
    return true;
  } else {
    return false;
  }
}

int main() {
  // struct stack s;
  // s.size = 80;
  // s.top = -1;
  // s.arr = new int[s.size];

  struct stack* s;
  s->size = 80;
  s->top = -1;
  s->arr = new int[s->size];

  // check if stack is empty
  if (isEmpty(s)) {
    std::cout << "Stack is empty";
  } else {
    std::cout << "Stack is not empty";
  }

  return 0;
}
