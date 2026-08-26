#include <cstddef>
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

struct Node* insertAtBeginning(struct Node* head, int data) {
  struct Node* ptr = new struct Node;
  ptr->next = head;
  ptr->data = data;
  return ptr;
}

struct Node* insertAtIndex(struct Node* head, int data, int index) {
  if (index == 0) {
    return insertAtBeginning(head, data);
  }

  struct Node* ptr = new struct Node;
  ptr->data = data;

  struct Node* p = head;
  int i = 0;

  while (i < index - 1 && p != NULL) {
    p = p->next;
    i++;
  }

  if (p == NULL) {
    delete ptr;
    return head;
  }

  ptr->next = p->next;
  p->next = ptr;

  return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
  struct Node* ptr = new struct Node;
  ptr->data = data;
  struct Node* p = head;

  while (p->next != NULL) {
    p = p->next;
  }

  p->next = ptr;
  ptr->next = NULL;

  return head;
}

struct Node* insertAfterNode(struct Node* head, struct Node* prevNode,
                             int data) {
  struct Node* ptr = new struct Node;
  ptr->data = data;

  ptr->next = prevNode->next;
  prevNode->next = ptr;

  return head;
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
  std::cout << "\n\n";

  // insert 10 at beginning
  std::cout << "Inserting 10 at the beginning of the linked list\n";
  head = insertAtBeginning(head, 10);

  traversal(head);
  std::cout << "\n\n";

  // insert 200 at index 2
  std::cout << "Inserting 200 at index 2 of the linked list\n";
  head = insertAtIndex(head, 200, 2);

  traversal(head);
  std::cout << "\n\n";

  // insert 20 at end
  std::cout << "Inserting 20 at the end of the linked list\n";
  head = insertAtEnd(head, 20);

  traversal(head);
  std::cout << "\n\n";

  // insert 45 after the third node
  std::cout << "Inserting 45 after the third node\n";
  head = insertAfterNode(head, third, 45);

  traversal(head);
  std::cout << "\n\n";

  return 0;
}
