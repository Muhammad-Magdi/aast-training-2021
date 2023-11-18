#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3;
int n, m, k, fedor, xOring, temp, ans;
int x[N];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d", &x[i]);
  }

  scanf("%d", &fedor);
  for (int i = 0; i < m; i++) {
    temp = 0;
    xOring = fedor ^ x[i];
    while (xOring) {
      temp += xOring & 1;
      xOring = xOring >> 1;
    }
    if (temp <= k)  ans++;
  }
  printf("%d\n", ans);
  return 0;
}