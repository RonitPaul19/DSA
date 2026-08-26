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

void traverse(struct stack* ptr) {
  if (isEmpty(ptr)) {
    std::cout << "Stack is empty\n\n";
    return;
  }

  for (int i = ptr->top; i >= 0; i--) {
    std::cout << ptr->arr[i] << " ";
  }

  std::cout << std::endl;
}

bool push(struct stack* ptr, int value) {
  if (isFull(ptr)) {
    std::cout << "Stack overflow\n\n";
    return false;
  } else {
    ptr->top++;
    ptr->arr[ptr->top] = value;
    return true;
  }
}

int pop(struct stack* ptr) {
  if (isEmpty(ptr)) {
    std::cout << "Stack underflow\n\n";
    return -1;
  } else {
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
  }
}

int main() {
  // Create stack
  struct stack* sp = new stack;

  sp->size = 10;
  sp->top = -1;
  sp->arr = new int[sp->size];

  std::cout << "Stack has been created successfully!\n\n";

  // Check if stack is empty
  if (isEmpty(sp)) {
    std::cout << "Stack is empty\n\n";
  } else {
    std::cout << "Stack is not empty\n\n";
  }

  // Check if stack is full
  if (isFull(sp)) {
    std::cout << "Stack is full\n\n";
  } else {
    std::cout << "Stack is not full\n\n";
  }

  // Push elements
  push(sp, 57);
  push(sp, 57);
  push(sp, 57);
  push(sp, 57);
  push(sp, 57);
  push(sp, 57);
  push(sp, 57);
  push(sp, 57);
  push(sp, 57);
  push(sp, 57);

  // This should cause stack overflow
  push(sp, 57);

  // Check if stack is empty
  if (isEmpty(sp)) {
    std::cout << "Stack is empty\n\n";
  } else {
    std::cout << "Stack is not empty\n\n";
  }

  // Check if stack is full
  if (isFull(sp)) {
    std::cout << "Stack is full\n\n";
  } else {
    std::cout << "Stack is not full\n\n";
  }

  // Pop an element
  std::cout << "Popped " << pop(sp) << " from the stack\n\n";

  // Check if stack is full again
  if (isFull(sp)) {
    std::cout << "Stack is full\n\n";
  } else {
    std::cout << "Stack is not full\n\n";
  }

  std::cout << "The stack is: ";
  traverse(sp);

  // Free dynamically allocated memory
  delete[] sp->arr;
  delete sp;

  return 0;
}
