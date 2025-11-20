//find a number that appears ones and other number twice
#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> a) {
  for (int i = 0; i < a.size(); i++)
  {
    int num = a[i];
    int count = 0;
    for (int j = 0; j < a.size(); j++)
    {
      if (a[j] == num)
        count++;
    }
    if (count == 1) return num;
  }
  return -1;
}

int main()
{
  vector<int> a = {4, 4, 3, 1, 2, 1, 2};
  int x = getSingleElement(a);
  cout<<x;
  return 0;
}
