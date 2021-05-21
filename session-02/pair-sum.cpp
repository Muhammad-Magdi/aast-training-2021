#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n, target;
int A[N];

void solveN2() {
  bool found = false;
  for (int i = 0; i < n; i++) { // O(n^2)
    for (int j = i+1; j < n; j++) {
      if (A[i] + A[j] == target) {
        found = true;
      }
    }
  }
  cout << (found ? "YES" : "NO") << endl;
}


// returns the index of `val` in the array
// if val doesn't exist in the array -> returns sz
int find(int* A, int sz, int val) { // O(n)
  for (int i = 0; i < sz; i++) {
    if (A[i] == val) {
      return i;
    }
  }
  return sz;
}

void solveNLogN() {  // O(n*log(n))
  bool found = false;
  sort(A, A+n);   // O(n*log(n))
  for (int i = 0; i < n; i++) { 
    int rem = target - A[i];
    // Does the array have the value `rem`?
    if (binary_search(A+i+1, A+n, rem)) { // O(log(n))
      found = true;
    }
  }
  cout << (found ? "YES" : "NO") << endl;
}

// O(n)

void solveNLogNCount() {  // O(n*log(n))
  int found = 0;
  sort(A, A+n);   // O(n*log(n))
  for (int i = 0; i < n; i++) { 
    int rem = target - A[i];
    int cnt = upper_bound(A+i+1, A+n, rem) - lower_bound(A+i+1, A+n, rem);
    found += cnt;
  }
  cout << found << endl;
}

int main() {
  cin >> n >> target;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  cout << "N2 says: ";
  solveN2();
  cout << "NLogN says: ";
  solveNLogN();
  cout << "NLogNCount says: ";
  solveNLogNCount();
  return 0;
}

/*
  0- Why?
  1- Name
  2- Parameters
  3- Return
  4- Time Complexity
*/

// sort
// find
// binary_search
// lower_bound
// upper_bound

// + Naive Sorting + merge + mergeSort