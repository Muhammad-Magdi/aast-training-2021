#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

char s[N];
int m, a, freq[N], n;

int main() {
  scanf("%s %d", s, &m);
  n = strlen(s);
  while (m--) {
    scanf("%d", &a);
    freq[a]++;
  }

  for (int i = 1; i <= n / 2; ++i) {
    freq[i] += freq[i - 1];
  }

  for (int i = 1; i <= n / 2; ++i)
    if (freq[i] % 2 != 0)
      swap(s[i - 1], s[n - i]);

  printf("%s\n", s);
  return 0;
}