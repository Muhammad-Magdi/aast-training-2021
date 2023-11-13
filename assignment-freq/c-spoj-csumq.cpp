#include <cstdio>

using namespace std;

const int N = 1e5 + 5;

int n, q, u, v;
long long A[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", A + i);
    A[i] += A[i - 1];
  }

  scanf("%d", &q);
  while (q--) {
    scanf("%d %d", &u, &v); // The array "A" is one-based, while "u" and "v" are zero-based
    printf("%lld\n", A[v + 1] - A[u]);
  }
  return 0;
}