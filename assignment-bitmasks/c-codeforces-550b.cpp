#include <bits/stdc++.h>

using namespace std;
const int N = 2e2;
int n, l, r, x, A[20], maxi, mini, sum, ans;

int main() {
  scanf("%d %d %d %d", &n, &l, &r, &x);
  for (int i = 0; i < n; ++i)
    scanf("%d", &A[i]);

  for (int mask = 0; mask < (1 << n); ++mask) {
    sum = 0, maxi = INT_MIN, mini = INT_MAX;
    for (int j = 0; j < n; ++j) {
      if (mask & (1 << j)) {
        sum += A[j];
        maxi = max(maxi, A[j]);
        mini = min(mini, A[j]);
      }
    }
    if (sum >= l && sum <= r && maxi - mini >= x) ++ans;
  }
  printf("%d\n", ans);
}