#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define isON(n, k) (((n) >> (k)) & 1)

const int N = 1e5 + 5;
int t, target, n, A[25];

int main() {  // O(n*(2^n))
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &target, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", A + i);
    }

    bool valid = false;
    for (int subset = 0; subset < (1 << n); subset++) {
      int sum = 0;
      for (int k = 0; k < n; k++) {
        if (isON(subset, k)) {
          sum += A[k];
        }
      }
      if (sum == target) {
        valid = true;
        break;
      }
    }
    puts(valid ? "YES" : "NO");
  }
  return 0;
}