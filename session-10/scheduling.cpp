#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define END first
#define START second

using namespace std;

const int N = 1e5+5;

int n;
pair<int, int> A[N];

int main() {    // O(n*log(n))
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &A[i].START, &A[i].END);
  }
  sort(A, A+n);
  int ans = 1;
  int busyUntil = A[0].END;
  for (int i = 1; i < n; i++) {
    if (A[i].START > busyUntil) {
      ans++;
      busyUntil = A[i].END;
    }
  }
  printf("%d\n", ans);
  return 0;
}