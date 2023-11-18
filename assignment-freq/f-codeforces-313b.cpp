#include <bits/stdc++.h>

using namespace std;

const int N = 2e4;
int n, m, l, r, pre[100009];
char s[100009];

int main() {
  scanf("%s", s);
  n = strlen(s);
  scanf("%d", &m);
  for (int i = 1; i < n; ++i) {
    pre[i] = pre[i - 1] + (s[i] == s[i - 1]);
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &l, &r);
    printf("%d\n", pre[r - 1] - pre[l - 1]);
  }
  return 0;
}