#include <cstddef>
#include <cstdlib>
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

// Deleting the first element in the linked list
struct Node* deleteAtFirst(struct Node* head) {
  struct Node* ptr = head;
  head = head->next;
  free(ptr);
  return head;
}

// Deleting element at index
struct Node* deleteAtIndex(struct Node* head, int index) {
  struct Node* p = head;
  struct Node* q = head->next;

  for (int i = 0; i < index - 1; i++) {
    p = p->next;
    q = q->next;
  }

  p->next = q->next;
  free(q);

  return head;
}

// Deleting the last node
struct Node* deleteAtLast(struct Node* head) {
  struct Node* p = head;
  struct Node* q = head->next;

  while (q->next != NULL) {
    p = p->next;
    q = q->next;
  }

  p->next = NULL;
  free(q);
  return head;
}

int main() {
  struct Node* head;
  struct Node* second;
  struct Node* third;
  struct Node* fourth;
  struct Node* fifth;
  struct Node* sixth;

  // Allocate memory for nodes in the linked list in heap
  head = new struct Node;
  second = new struct Node;
  third = new struct Node;
  fourth = new struct Node;
  fifth = new struct Node;
  sixth = new struct Node;

  // link first and second nodes
  head->data = 4;
  head->next = second;

  // link second and third nodes
  second->data = 3;
  second->next = third;

  // link third and fourth nodes
  third->data = 8;
  third->next = fourth;

  // link fourth and fifth nodes
  fourth->data = 1;
  fourth->next = fifth;

  // link fifth and sixth nodes
  fifth->data = 10;
  fifth->next = sixth;

  // link sixth node and NULL
  sixth->data = 2;
  sixth->next = NULL;

  std::cout << "Initial linked list : ";
  traversal(head);
  std::cout << std::endl;

  head = deleteAtFirst(head);

  std::cout << "Linked list before deleting first element : ";
  traversal(head);
  std::cout << std::endl;

  int index = 1;
  head = deleteAtIndex(head, index);

  std::cout << "Linked list before deleting element at index " << index << ": ";
  traversal(head);
  std::cout << std::endl;

  head = deleteAtLast(head);

  std::cout << "Linked list after deleting last node : ";
  traversal(head);
  std::cout << std::endl;

  return 0;
}
