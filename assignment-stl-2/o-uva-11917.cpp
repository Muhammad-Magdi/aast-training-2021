#include <iostream>
#include <map>

using namespace std;

string str;
int t, n, d;
map<string, int> mp;

int main() {
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    mp.clear();

    cin >> n;
    while (n--) {
      cin >> str >> d;
      mp[str] = d;
    }
    cin >> d >> str;
    printf("Case %d: ", tc);
    if (!mp.count(str)) {
      puts("Do your own homework!");
      continue;
    }
    int duration = mp[str];
    puts(duration <= d ? "Yesss" : duration <= d + 5 ? "Late" : "Do your own homework!");
  }
  return 0;
}