#include <iostream>

struct stack {
  int size;
  int top;
  int* arr;
};

// Check if stack is empty
bool isEmpty(struct stack* ptr) { return ptr->top == -1; }

// Check if stack is full
bool isFull(struct stack* ptr) { return ptr->top == ptr->size - 1; }

// Traverse stack from top to bottom
void traverse(struct stack* ptr) {
  if (isEmpty(ptr)) {
    std::cout << "Stack is empty\n\n";
    return;
  }

  for (int i = ptr->top; i >= 0; i--) {
    std::cout << ptr->arr[i] << " ";
  }

  std::cout << "\n\n";
}

// Push element into stack
bool push(struct stack* ptr, int value) {
  if (isFull(ptr)) {
    std::cout << "Stack overflow\n\n";
    return false;
  }

  ptr->top++;
  ptr->arr[ptr->top] = value;

  return true;
}

// Pop element from stack
int pop(struct stack* ptr) {
  if (isEmpty(ptr)) {
    std::cout << "Stack underflow\n\n";
    return -1;
  }

  int val = ptr->arr[ptr->top];
  ptr->top--;

  return val;
}

// Get top element
int stackTop(struct stack* sp) {
  if (isEmpty(sp)) {
    std::cout << "Stack is empty\n";
    return -1;
  }

  return sp->arr[sp->top];
}

// Get bottom element
int stackBottom(struct stack* sp) {
  if (isEmpty(sp)) {
    std::cout << "Stack is empty\n";
    return -1;
  }

  return sp->arr[0];
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

  // Try top and bottom on empty stack
  std::cout << "Trying to get stack top:\n";
  stackTop(sp);

  std::cout << "\nTrying to get stack bottom:\n";
  stackBottom(sp);

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

  std::cout << "\n";

  // Check top and bottom
  std::cout << "Stack top is " << stackTop(sp) << std::endl;
  std::cout << "Stack bottom is " << stackBottom(sp) << std::endl;

  // Traverse stack
  std::cout << "The stack is: ";
  traverse(sp);

  // Pop an element
  std::cout << "Popped " << pop(sp) << " from the stack\n\n";

  // Check top and bottom again
  std::cout << "Stack top is " << stackTop(sp) << std::endl;
  std::cout << "Stack bottom is " << stackBottom(sp) << std::endl;

  // Traverse stack again
  std::cout << "The stack is: ";
  traverse(sp);

  // Free dynamically allocated memory
  delete[] sp->arr;
  delete sp;

  return 0;
}
