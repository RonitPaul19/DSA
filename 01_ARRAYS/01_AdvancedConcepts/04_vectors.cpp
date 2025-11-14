#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;       // empty vector

    v.push_back(10);     // append elements
    v.push_back(20);
    v.push_back(30);

    cout << v[1] << endl; // access -> 20

    // iterate
    for (int x : v)
        cout << x << " "; // 10 20 30
    cout << endl;

    v.pop_back();         // remove last element (30)

    cout << "Size: " << v.size() << endl; // Size: 2
}
