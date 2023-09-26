#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int x;
vector<int> v;
multiset<int> ms;

int main() {
  while (~scanf("%d", &x)) {
    v.push_back(x);
    ms.insert(x);
  }

  for (int val : v) {
    int val_count = ms.count(val);
    if (val_count) {
      printf("%d %d\n", val, val_count);
      ms.erase(val);
    }
  }

  return 0;
}