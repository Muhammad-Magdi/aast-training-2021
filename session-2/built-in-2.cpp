#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

// Odd Before Even
bool myComparator(int a, int b) {
  return a%2 == b%2 || (a%2 != 0 && b%2 == 0);
  // if (a%2 == b%2 || (a%2 != 0 && b%2 == 0)) {
  //   return true;
  // } else {
  //   return false;
  // }
}

bool isGreaterThan(int a, int b) {
  return a > b;
  // if (a > b) {
  //   return true;
  // } else {
  //   return false;
  // }
}

int A[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A+n, myComparator);
  // n = unique(A, A+n) - A;
  // reverse(A, A+n);
  for (int i = 0; i < n; i++) {
    cout << A[i] << " \n"[i == n-1];
  }
  return 0;
}

// next_permutation