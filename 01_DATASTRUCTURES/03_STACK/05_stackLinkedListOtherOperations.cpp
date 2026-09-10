#include <iostream>

struct Node {
  int data;
  Node* next;
};

void traversal(Node* ptr) {
  while (ptr != nullptr) {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }

  std::cout << '\n';
}

bool isEmpty(Node* top) { return top == nullptr; }

Node* push(Node* top, int x) {
  Node* n = new Node;

  n->data = x;
  n->next = top;

  return n;
}

Node* pop(Node* top) {
  if (isEmpty(top)) {
    std::cout << "Stack underflow\n";
    return nullptr;
  }

  Node* n = top;
  top = top->next;

  delete n;

  return top;
}

int peek(Node* top, int pos) {
  Node* ptr = top;

  for (int i = 0; i < pos - 1 && ptr != nullptr; i++) {
    ptr = ptr->next;
  }

  if (ptr != nullptr) {
    return ptr->data;
  }

  return -1;
}

int stackTop(Node* top) {
  if (isEmpty(top)) {
    std::cout << "Stack is empty\n";
    return -1;
  }

  return top->data;
}

int stackBottom(Node* top) {
  if (isEmpty(top)) {
    std::cout << "Stack is empty\n";
    return -1;
  }

  Node* ptr = top;

  while (ptr->next != nullptr) {
    ptr = ptr->next;
  }

  return ptr->data;
}

int main() {
  Node* top = nullptr;

  top = push(top, 78);
  top = push(top, 50);
  top = push(top, 25);

  std::cout << "Linked list: ";
  traversal(top);

  std::cout << "Peek: " << peek(top, 1) << '\n';
  std::cout << "Top: " << stackTop(top) << '\n';
  std::cout << "Bottom: " << stackBottom(top) << '\n';

  top = pop(top);

  traversal(top);

  return 0;
}
