#include <cstdio>
#include <set>

using namespace std;

int n, k, x;

int main() {
  while (scanf("%d", &n), n) {
    multiset<int> s;
    long long cost = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      while (k--) {
        scanf("%d", &x);
        s.insert(x);
      }
      int lowest = *s.begin();
      s.erase(s.begin());

      int highest = *prev(s.end());
      s.erase(prev(s.end()));
      cost += (highest - lowest);
    }
    printf("%lld\n", cost);
  }
  return 0;
}