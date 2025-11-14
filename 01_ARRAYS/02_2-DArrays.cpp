#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a[5][5] = {};

  // inputting in the array
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << "Input elements " << "[" << i << "]" << "[" << j << "]";
      cin >> a[i][j];
    }
  }
  cout << "\n";
  // outputting in the array
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
