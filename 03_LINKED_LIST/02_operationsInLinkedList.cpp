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

// convert an array to linked list
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

// find the length of the linked list
int lengthOfLL(Node *head) {
  int cnt=0;
  Node *temp = head;
  while (temp) {
    temp = temp->next;
    cnt++;
  }
  return cnt;
}

// searching in a linked list
int checkIfPresent(Node *head, int val) {
  Node *temp = head;
  while (temp) {
    if(temp->data == val) return 1;
    temp = temp->next;
  }
  return 0;
}

int main()
{
  vector<int> arr = {2, 5, 8, 7};
  Node *head = convertArr2LL(arr);

  Node *temp = head;

  cout<<"The LL is : ";
  while(temp) {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;

  int n = lengthOfLL(head);
  cout<<"Lenght of LL is "<<n<<endl;

  if(checkIfPresent(head, 5)) {
    cout<<"element is present";
  } else {
    cout<<"not present";
  }

  return 0;
}
