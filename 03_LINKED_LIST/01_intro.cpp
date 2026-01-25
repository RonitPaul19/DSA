/*

*) Not contiguous - elements are not placed serially in the memory.
*) Flexible - size of the linked list can be increased or decreased.
*) head of the linked list in the starting element.


  |----|----|     |----|----|     |----|----|
  |    | m1 |---->|    | m2 |---->|    | m3 |
  |----|----|     |----|----|     |----|----|
                                       ^
                                       |
                                       |
                                      tail
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node *next;

  public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }
};

int main() {
  vector<int> arr = {2,5,8,7};

  Node *x = new Node(arr[0], nullptr);
  cout << x->data<<endl;

  Node *y = new Node(arr[1], nullptr);
  cout << y->data<<endl;

  Node *z = new Node(arr[2], nullptr);
  cout << z->data<<endl;

  return 0;
}
