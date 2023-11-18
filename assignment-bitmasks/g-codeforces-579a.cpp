#include <cstdio>

using namespace std;

int n, ans;

int main() {
  scanf("%d", &n);
  while (n) {
    if (n & 1)	++ans;
    n = (n >> 1);
  }
  printf("%d\n", ans);
}