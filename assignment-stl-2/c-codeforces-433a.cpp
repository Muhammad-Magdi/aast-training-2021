#include <bits/stdc++.h>

using namespace std;

set<char> s;
char c;

int main() {
  while (cin >> c) {
    if (c == '{' || c == '}' || c == ' ' || c == ',')	continue;
    s.insert(c);
  }

  printf("%d\n", (int)s.size());
  return 0;
}