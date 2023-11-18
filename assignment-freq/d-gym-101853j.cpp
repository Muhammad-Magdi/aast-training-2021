#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

char s[N];
int t, n, x, freq[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    fill(freq, freq + N, 0);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      freq[x]++;
    }

    int mx = 0;
    for (int i = 0; i <= 10001; ++i) {
      if (freq[i] + freq[i + 1] > mx) {
        mx = freq[i] + freq[i + 1];
      }
    }
    printf("%d\n", mx);
  }
  return 0;
}