#include <iostream>

struct Node {
  int data;
  struct Node* next;
};

void traversal(struct Node* ptr) {
  while (ptr != NULL) {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
}

int main() {
  struct Node* head;
  struct Node* second;
  struct Node* third;
  struct Node* fourth;

  // Allocate memory for nodes in the linked list in heap
  head = new struct Node;
  second = new struct Node;
  third = new struct Node;
  fourth = new struct Node;

  // link first and second nodes
  head->data = 7;
  head->next = second;

  // link second and third nodes
  second->data = 11;
  second->next = third;

  // link third and fourth nodes
  third->data = 66;
  third->next = fourth;

  // link fourth and NULL
  fourth->data = 100;
  fourth->next = NULL;

  traversal(head);

  return 0;
}
