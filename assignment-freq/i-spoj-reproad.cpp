#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e4 + 5;

typedef long long ll;

int t, n, k;
int A[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &A[i]);
      A[i] = !A[i];
      A[i] += A[i - 1];
    }

    int mx = 0;
    for (int st = 1; st <= n; st++) {
      int en = upper_bound(A + 1, A + n + 1, k + A[st - 1]) - A;
      mx = max(mx, en - st);
    }
    printf("%d\n", mx);
  }
  return 0;
}