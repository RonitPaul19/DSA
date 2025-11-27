// find occurences of an element in an array with duplicates
#include <bits/stdc++.h>
using namespace std;

// find first index of x
int firstPos(vector<int>& a, int x) {
    int low = 0, high = a.size() - 1, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == x) {
            ans = mid;
            high = mid - 1;  // go left
        }
        else if (a[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

// find last index of x
int lastPos(vector<int>& a, int x) {
    int low = 0, high = a.size() - 1, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == x) {
            ans = mid;
            low = mid + 1;  // go right
        }
        else if (a[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

int countOccurrences(vector<int> a, int x) {
    int first = firstPos(a, x);
    if (first == -1) return 0;
    int last = lastPos(a, x);
    return last - first + 1;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    int x = 4;
    int ans = countOccurrences(a, x);
    cout << ans;
    return 0;
}
