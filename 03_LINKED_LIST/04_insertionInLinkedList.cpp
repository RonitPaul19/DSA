#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }
};

// Convert array (vector) to linked list
Node *convertArr2LL(vector<int> &arr)
{
  if (arr.size() == 0)
    return nullptr;

  Node *head = new Node(arr[0], nullptr);
  Node *mover = head;

  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr);
    mover->next = temp;
    mover = temp;
  }

  return head;
}

// Print linked list
void print(Node *head)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// insert at the head of the linked list
Node *insertAtHead(Node *head, int val)
{
  Node *temp = new Node(val, head);
  return temp;

  // or directly we can do like :-  "return new Node(val, head);"
}

Node *insertAtTail(Node *head, int val)
{
  if (head == NULL)
  {
    return new Node(val, head);
  }

  Node *temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }

  Node *newNode = new Node(val, NULL);
  temp->next = newNode;

  return head;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node *head = convertArr2LL(arr);

  print(head);

  head = insertAtHead(head, 100);
  cout << "Inserting 100 in the head : \n";

  print(head);

  head = insertAtTail(head, 200);
  cout << "Inserting 200 in the tail : \n";

  print(head);

  return 0;
}
