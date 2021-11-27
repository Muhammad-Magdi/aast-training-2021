#include <iostream>
#include <utiliy>
#include <algorithm>

using namespace std;

/*
  1- When? Why?
  2- How to use?
  3- How does it work?  - Data Structures

  STL - Standard Template Library

  (x, y, z)
  (-1, 13)
  (1, 2)
  (0, 5)
  (3, 2)
  (3, 4)

  1 2 3 4 => 1 2 3 4
  -1 -2 -3 -4 => -4 -3 -2 -1 => 4 3 2 1
*/

const int N = 1e5;

int n;
pair<int, pair<int, int>> A[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i].first >> A[i].second.first >> A[i].second.second;
    A[i].second.second *= -1;
  }

  sort(A, A + n);

  for (int i = 0; i < n; i++) {
    cout << A[i].first << " " << A[i].second.first << " " << -1 * A[i].second.second << endl;
  }
  return 0;
}