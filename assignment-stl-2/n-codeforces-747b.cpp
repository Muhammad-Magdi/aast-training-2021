#include <bits/stdc++.h>

using namespace std;

int n, f[30], sum;
string s;

int main() {
  cin >> n >> s;
  if (n % 4 != 0) {
    puts("===");
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] != '?')  f[s[i] - 'A']++;
  }

  f['A' - 'A'] -= n / 4;    // Note: 'A' - 'A' = 0
  f['T' - 'A'] -= n / 4;
  f['G' - 'A'] -= n / 4;
  f['C' - 'A'] -= n / 4;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      if (f['A' - 'A'] < 0) {
        s[i] = 'A';
        f['A' - 'A']++;
      } else if (f['G' - 'A'] < 0) {
        s[i] = 'G';
        f['G' - 'A']++;
      } else if (f['T' - 'A'] < 0) {
        s[i] = 'T';
        f['T' - 'A']++;
      } else if (f['C' - 'A'] < 0) {
        s[i] = 'C';
        f['C' - 'A']++;
      }
    }
  }

  if (f['A' - 'A'] != 0 || f['C' - 'A'] != 0 || f['G' - 'A'] != 0 || f['T' - 'A'] != 0)
    puts("===");
  else  cout << s << endl;

  return 0;
}