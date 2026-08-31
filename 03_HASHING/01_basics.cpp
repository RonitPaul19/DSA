#include <iostream>

// Hashing is used to store and retrieve data extremely quickly using a key

// Problem - Find frequency of each elements in the array. Let array can only
//           have an elemnt of max 12

/*

Example Input -
- - - - - - -
5
1 3 2 1 3
5
1
4
2
3
12

Example Output -
- - - - - - - -
2
0
1
2
0

*/

int main() {
  int n;
  std::cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  // precompute
  int hash[13] = {0};  // hash[13] is used since it is given the array can have
                       // max element upto 12

  for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }

  int q;
  std::cin >> q;
  while (q--) {
    int number;
    std::cin >> number;

    // fetch
    std::cout << "ans - " << hash[number] << std::endl;
  }

  return 0;
}
