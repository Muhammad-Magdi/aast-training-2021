#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const string REPEATED = "..";   // Any value not expected in the input
string s;
map<string, string> mp;

inline bool is_upper(char c) {
  return c >= 'A' && c <= 'Z';
}

inline char char_to_lower(char c) {
  return c + 'a' - 'A';
}

string string_to_lower(string s) {
  string ret(s);

  for (int i = 0; i < s.length(); i++) {
    if (is_upper(ret[i])) {
      ret[i] = char_to_lower(ret[i]);
    }
  }

  return ret;
}

string canonize(string s) {
  s = string_to_lower(s);
  sort(s.begin(), s.end());

  return s;
}

int main() {
  ios_base::sync_with_stdio(false);

  while (cin >> s, s != "#") {
    string canonized = canonize(s);
    if (mp.count(canonized)) mp[canonized] = REPEATED;
    else mp[canonized] = s;
  }

  vector<string> ananagrams;
  for (pair<string, string> p : mp) {
    if (p.second != REPEATED) ananagrams.push_back(p.second);
  }
  sort(ananagrams.begin(), ananagrams.end());

  for (string ananagram : ananagrams) {
    cout << ananagram << "\n";
  }
  return 0;
}