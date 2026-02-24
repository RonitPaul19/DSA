#include <iostream>
#include <vector>
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

// delete head node of a linked list
Node *removeHead(Node *head)
{
  if (head == nullptr)
    return head;

  Node *temp = head;
  head = head->next;
  delete temp;

  return head;
}

// delete the tail of the linked list
Node *deleteTail(Node *head)
{
  if(head == NULL || head->next == NULL)
    return NULL;

  Node *temp = head;
  while(temp->next->next != NULL)
    temp = temp->next;

  delete temp->next;
  temp->next = NULL;

  return head;
}

// delete the Kth element of the linked list
Node *deleteKthElement(Node *head, int k) {
  if(head == NULL)
    return head;

  else if(k == 1) {
    Node *temp = head;
    head = head -> next;
    free(temp);
    return head;
  }

  int cnt = 0;
  Node *temp = head, *prev = NULL;

  while(temp != NULL) {
    cnt++;
    if(cnt == k) {
      prev->next = prev->next->next;
      free(temp);
      break;
    }

    prev = temp;
    temp = temp->next;
  }

  return head;
}

// remove an element from the linked list
Node *deleteElement(Node *head, int element) {
  if(head == NULL)
    return head;

  else if(head->data == element) {
    Node *temp = head;
    head = head -> next;
    free(temp);
    return head;
  }

  Node *temp = head, *prev = NULL;

  while(temp != NULL) {
    if(temp->data == element) {
      prev->next = prev->next->next;
      free(temp);
      break;
    }

    prev = temp;
    temp = temp->next;
  }

  return head;
}

int main()
{
  // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
  // Node *head1 = convertArr2LL(arr);

  // print(head1);

  // cout << "Removing the head of the linked list \n ";
  // head1 = removeHead(head1);

  // print(head1);

  // cout << "Removing the tail of the linked list \n ";
  // head1 = deleteTail(head1);

  // print(head1);

  vector<int> arr2 = {2, 4, 6, 8, 10, 12, 14, 16};
  Node *head2 = convertArr2LL(arr2);

  print(head2);

  cout<<"Deleting element no. 3 from the linked list : \n";
  head2 = deleteKthElement(head2, 3);

  print(head2);

  cout<<"Deleting element 14 from the linked list : \n";
  head2 = deleteElement(head2, 14);

  print(head2);

  return 0;
}
