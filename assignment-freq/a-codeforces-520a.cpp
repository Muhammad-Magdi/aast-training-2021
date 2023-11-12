#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e4, OO = 0x3f3f3f3f;

char s[N];
int freq[26], n;

int main() {
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; ++i)            //Canonical Form (Lower Case)
    if (isupper(s[i]))
      s[i] = tolower(s[i]);

  for (int i = 0; i < n; ++i)
    freq[s[i] - 'a']++;

  for (int i = 0; i < 26; ++i) {
    if (freq[i] == 0) {
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");
  return 0;
}