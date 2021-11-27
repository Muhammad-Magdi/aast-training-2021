#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ON(n, k) ((n) | (1 << (k)))
#define OFF(n, k) ((n) & ~(1 << (k)))
#define isON(n, k) (((n) >> (k)) & 1)
// #define isON(n, k) ((n) & (1 << (k)))

const int N = 1e5 + 5;

string getBinary(int x) {
  string ret = "";
  for (int i = 3; i >= 0; i--) {
    ret += to_string(isON(x, i));
  }
  return ret;
}

inline int twoPower(int k) {
  return 1 << k;
}

inline bool isOdd(int x) {
  return x & 1;
}

// Meet in the middle

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