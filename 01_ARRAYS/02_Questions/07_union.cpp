#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
vector<int> UNION_Brute(vector<int> a, vector<int> b)
{
  set<int> st;
  for (int el : a)
    st.insert(el);
  for (int el : b)
    st.insert(el);

  // convert set to vector
  vector<int> result(st.begin(), st.end());
  return result;
}

// OPTIMAL APPROACH (two-pointer method)
vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
  int i = 0, j = 0;
  vector<int> Union;

  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j])
    {
      if (Union.empty() || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    }
    else
    {
      if (Union.empty() || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }

  while (i < n)
  {
    if (Union.empty() || Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }

  while (j < m)
  {
    if (Union.empty() || Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }

  return Union;
}

int main()
{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};

  vector<int> Union = FindUnion(arr1, arr2, n, m);

  cout << "Union of arr1 and arr2 is:\n";
  for (auto &val : Union)
    cout << val << " ";
  cout << endl;

  // Testing brute force
  vector<int> bruteUnion = UNION_Brute(vector<int>(arr1, arr1 + n), vector<int>(arr2, arr2 + m));
  cout << "Union using brute force is:\n";
  for (auto &val : bruteUnion)
    cout << val << " ";
  cout << endl;

  return 0;
}
