#include <cstdio>
#include <vector>
#include <algorithm>

#define TWO_POWER(x) (1 << (x))
#define IS_ON(msk, b) (((msk) >> (b)) & 1)

using namespace std;
const int N = 9;

int n;
vector<int> v;

// replaces every '0 bit' by a '4' and every '1 bit' by a '7'
int replace_values(int msk, int length) {
  int ret = 0;
  for (int i = 0; i < length; i++) {
    if (IS_ON(msk, length - i - 1)) ret = ret * 10 + 7;
    else ret = ret * 10 + 4;
  }
  return ret;
}

void generate() {
  for (int length = 1; length <= N; ++length) {
    for (int msk = 0; msk < TWO_POWER(length); ++msk) {
      v.push_back(replace_values(msk, length));
    }
  }
}

int main() {
  generate();
  scanf("%d", &n);
  printf("%d\n", (int)(lower_bound(v.begin(), v.end(), n) - v.begin()) + 1);
  return 0;
}