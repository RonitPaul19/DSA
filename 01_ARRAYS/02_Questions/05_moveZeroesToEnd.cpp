// move zeroes to the end of the array
#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeroes_BRUTE(vector<int> &arr)
{
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
            temp.push_back(arr[i]);
    }
    // Add the right number of zeros
    int zeros = arr.size() - temp.size();
    for (int i = 0; i < zeros; i++)
    {
        temp.push_back(0);
    }
    return temp;
}

int main()
{
  vector<int> arr = {0, 1, 0, 3, 12};
  vector<int> result = moveZeroes_BRUTE(arr);

  cout << "Array after moving zeroes: ";
  for (int num : result)
  {
    cout << num << " ";
  }

  cout << endl;
  return 0;
}
