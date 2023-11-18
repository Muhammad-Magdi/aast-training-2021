#include <bits/stdc++.h>

using namespace std;

const int N = 2e1 + 5;

int n, length, A[N];

int main() {
  while (~scanf("%d", &length)) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)    scanf("%d", A + i);

    int mx = 0;
    int bestMask;
    for (int msk = 0; msk < (1 << n); ++msk) {
      int sum = 0;
      for (int k = 0; k < n; ++k)
        if ((msk >> k) & 1)  sum += A[k];
      if (sum <= length) {
        if (sum > mx) {
          mx = sum;
          bestMask = msk;
        }
      }
    }

    for (int k = 0; k < n; ++k) {
      if ((bestMask >> k) & 1)  printf("%d ", A[k]);
    }
    printf("sum:%d\n", mx);
  }
  return 0;
}