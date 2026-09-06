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

bool isFull() {
  Node* p = new Node;

  if (p == nullptr) {
    return true;
  } else {
    delete p;
    return false;
  }
}

Node* push(Node* top, int x) {
  if (isFull()) {
    std::cout << "Stack overflow\n";
    return top;
  }

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

int main() {
  Node* top = nullptr;

  top = push(top, 78);
  top = push(top, 50);
  top = push(top, 25);

  std::cout << "Stack: ";
  traversal(top);

  top = pop(top);

  std::cout << "After pop: ";
  traversal(top);

  return 0;
}
