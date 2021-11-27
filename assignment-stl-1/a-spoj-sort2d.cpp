#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int t, n;
pair<int, int> A[N];

int main() {
  // cin >> t;
  scanf("%d", &t);
  while (t--) {
    // cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      // cin >> A[i].first >> A[i].second;
      scanf("%d %d", &A[i].first, &A[i].second);
      A[i].second *= -1;
    }
    sort(A, A + n);
    for (int i = 0; i < n; ++i) {
      printf("%d %d\n", A[i].first, -1 * A[i].second);
    }
    // cout << A[i].first << " " << -1*A[i].second << endl;
  }
  return 0;
}