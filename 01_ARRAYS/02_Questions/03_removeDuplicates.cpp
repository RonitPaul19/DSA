// removes duplicates from a sorted array
#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(vector<int> &a)
{
  int j = 0;
  for (int i = 1; i < a.size(); i++)
  {
    if (a[i] != a[j])
    {
      j++;
      a[j] = a[i];
    }
  }
  a.resize(j + 1);
}

int main()
{
  vector<int> a = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7};
  removeDuplicates(a);
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}
