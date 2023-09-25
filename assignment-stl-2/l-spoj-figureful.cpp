#include <iostream> 
#include <map>

using namespace std;

int n, u, v, t;
map<pair<int, int>, string> mp;
char fig[21];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %s", &u, &v, fig);
    mp[{u, v}] = string(fig);
  }

  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &u, &v);
    printf("%s\n", mp[{u, v}].c_str());
  }
  return 0;
}