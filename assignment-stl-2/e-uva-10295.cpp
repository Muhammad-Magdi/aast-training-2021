#include <cstdio>
#include <string>
#include <map>

using namespace std;

int m, n, v;
char str[17];
map<string, int> mp;

int main() {
  scanf("%d %d", &m, &n);
  while (m--) {
    scanf("%s %d", str, &v);
    mp[string(str)] = v;
  }

  while (n--) {
    int sum = 0;
    while (scanf("%s", str), str[0] != '.') sum += mp[string(str)];
    printf("%d\n", sum);
  }
  return 0;
}