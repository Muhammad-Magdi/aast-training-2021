#include <cstdio>
#include <cmath>

using namespace std;

long long l, r, msk;

int main() {
  scanf("%lld%lld", &l, &r);
  for (int i = log2(r); ~i; --i) {
    msk |= (1ll << i);
    if (msk <= r && msk > l)
      return printf("%lld\n", msk ^ (msk - 1)), 0;
    if (msk > r) msk &= ~(1ll << i);
  }
  puts("0");
  return 0;
}