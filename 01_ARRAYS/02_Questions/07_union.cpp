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
vector<int> FindUnion(vector<int> a, vector<int> b) {
  int n1 = a.size();
  int n2 = b.size();
  int i = 0, j = 0;
  vector<int> unionArr;

  while(i<n1 && j<n2) {
    if(a[i] <= b[j]) {
      if(unionArr.size() == 0 || unionArr.back() != a[i]) {
        unionArr.push_back(a[i]);
      }
      i++;
    } else {
      if(unionArr.size() == 0 || unionArr.back() != b[j]) {
        unionArr.push_back(b[j]);
      }
      j++;
    }
  }

  while (j < n2)
  {
    if (unionArr.size() == 0 || unionArr.back() != b[j])
    {
      unionArr.push_back(b[j]);
    }
    j++;
  }

  while (i < n1)
  {
    if (unionArr.size() == 0 || unionArr.back() != a[i])
    {
      unionArr.push_back(a[i]);
    }
    i++;
  }

  return unionArr;
}
/*
time complexity = O(n1 + n2)
space complexity = O(n1 + n2) // for returning the array
*/

int main()
{
  vector <int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector <int> arr2 = {2, 3, 4, 4, 5, 11, 12};

  vector<int> Union = FindUnion(arr1, arr2);

  cout << "Union of arr1 and arr2 is:\n";
  for (auto &val : Union)
    cout << val << " ";
  cout << endl;

  // Testing brute force
  //vector<int> bruteUnion = UNION_Brute(vector<int>(arr1, arr1 + n), vector<int>(arr2, arr2 + m));
  //cout << "Union using brute force is:\n";
  //for (auto &val : bruteUnion)
    //cout << val << " ";
  //cout << endl;

  return 0;
}
