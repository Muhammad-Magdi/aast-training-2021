#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
int n, m, A[N], q;

int main() {
  scanf("%d", &n);
  scanf("%d", &A[0]);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &A[i]);
    A[i] += A[i - 1];
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &q);
    printf("%d\n", lower_bound(A, A + n, q) - A + 1);
  }
  return 0;
}