#include <cstdio>
#include <vector>
#include <algorithm>

#define TWO_POWER(x) (1 << (x))
#define IS_ON(msk, b) (((msk) >> (b)) & 1)

using namespace std;

const int N = 11;
int n;
vector<long long> v;

bool is_super_lucky(int msk, int length) {
  int count_ones = 0;
  while (msk) {
    if (IS_ON(msk, 0))  count_ones++;
    msk = msk >> 1;
  }

  return (count_ones << 1) == length;
}

// replaces every '0 bit' by a '4' and every '1 bit' by a '7'
long long replace_values(int msk, int length) {
  long long ret = 0;
  for (int i = 0; i < length; i++) {
    if (IS_ON(msk, length - i - 1)) ret = ret * 10 + 7;
    else ret = ret * 10 + 4;
  }
  return ret;
}

void generate() {
  for (int length = 2; length < N; length += 2) {
    for (int msk = 0; msk < TWO_POWER(length); msk++) {
      if (is_super_lucky(msk, length)) v.push_back(replace_values(msk, length));
    }
  }
}

int main() {
  generate();
  scanf("%d", &n);
  printf("%lld\n", *lower_bound(v.begin(), v.end(), n));
  return 0;
}