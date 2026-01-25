#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Convert array (vector) to linked list
Node* convertArr2LL(vector<int>& arr) {
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0], nullptr);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Remove head node
Node* removeHead(Node* head) {
    if (head == nullptr) return head;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

// Print linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};

    Node* head = convertArr2LL(arr);
    head = removeHead(head); 
    print(head);

    return 0;
}
