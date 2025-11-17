// array left rotation
#include <bits/stdc++.h>
using namespace std;

// left rotate an array by 1 place
void leftRotateBy1(vector<int> &a)
{
  int n = a.size();
  int temp = a[0];
  for (int i = 1; i < n; i++) // start from 1 so that we can store this value in the previous index
  {
    a[i - 1] = a[i];
  }
  a[n - 1] = temp;
}

// left rotate an array by 'd' places
void leftRotateByD(vector<int> &a, int d)
{
  int n = a.size();
  d = d % n;
  reverse(a.begin(), a.begin() + d);
  reverse(a.begin() + d, a.begin() + n);
  reverse(a.begin(), a.begin() + n);
}

int main()
{
  vector<int> a = {1, 2, 3, 4, 5};
  cout << "Before left rotate by 1" << "\n";
  for (int el : a)
  {
    cout << el << " ";
  }
  cout << "\n";

  leftRotateBy1(a);

  cout << "after left rotate by 1" << "\n";
  for (int el : a)
  {
    cout << el << " ";
  }
  cout << "\n";

  int d = 3;
  leftRotateByD(a, d);
  cout << "After rotating the array by " << d << " places";
  for (int el : a)
  {
    cout << el << " ";
  }
  cout << "\n";
  return 0;
}
