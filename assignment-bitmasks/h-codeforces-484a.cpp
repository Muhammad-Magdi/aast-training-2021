#include <cstdio>

using namespace std;

int n;
long long l, r, ans;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%lld %lld", &l, &r);
    ans = l;
    for (int i = 0; i < 61; ++i)
      if ((ans | (1ll << i)) <= r) ans |= (1ll << i);
    printf("%lld\n", ans);
  }
  return 0;
}