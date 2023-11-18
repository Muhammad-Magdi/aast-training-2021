#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 5;

int n;
long long A[N], ans;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", A + i);

  sort(A, A + n);
  for (int i = 1; i < n; ++i) A[i] += A[i - 1];

  int last = 0;
  while (last <= n) {
    ans += A[n - 1] - (last ? A[last - 1] : 0);
    last += ((n - 1 - last) * 3) / 4 + 1;
  }

  printf("%lld\n", ans);
  return 0;
}