#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
  1- When? Why?
  2- How to use?
  3- How does it work?  - Data Structures

  STL - Standard Template Library
  1 2 3 4 5 6
  1 2 3 5 6
  1 2 3 4 5 6

  push_back() - amortized O(1)
  begin()
  end()
  size()
  pop_back()
  insert()  - O(n)
  erase() - O(n)
  1 2 3
*/

const int N = 1e5;

int n, x;
vector<int> v;
int main() {
  // cin >> n;
  // for (int i = 0; i < n; i++) {
  //   // cin >> A[i];
  //   cin >> x;
  //   v.push_back(x);
  // }

  // sort(v.begin(), v.end());

  // for (int i = 0; i < v.size(); i++) {
  //   cout << v[i] << endl;
  // }

  // for (int x : v) {
  //   cout << x << endl;
  // }

  // 1 2 3 -1 4 5 6
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  v.insert(v.begin() + 3, -1);
  v.erase(v.begin() + 2);
  for (int x : v) {
    cout << x << endl;
  }
  return 0;
}