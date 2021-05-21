#include <iostream>
#include <algorithm>

using namespace std;

/*
  1- When? Why?
  2- How to use?
  3- How does it work?  - Data Structures

  STL - Standard Template Library

  (x, y)
  (-1, 13)
  (1, 2)
  (0, 5)
  (3, 2)
  (3, 4)
*/

struct Point{
  int x;
  int y;
};

// true => don't swap
// false => swap
bool cmp(Point a, Point b) {
  if (a.x == b.x) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

const int N = 1e5;

int n;
Point A[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i].x >> A[i].y;
  }

  sort(A, A+n, cmp);

  for (int i = 0; i < n; i++) {
    cout << A[i].x << " " << A[i].y << endl;
  }
  return 0;
}