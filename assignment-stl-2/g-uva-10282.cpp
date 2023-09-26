#include<iostream>
#include<sstream>
#include<cstdio>
#include<map>

using namespace std;

string s, k, v;
map<string, string> mp;

int main() {
  ios_base::sync_with_stdio(false);

  while (getline(cin, s), s.length() > 0) {
    istringstream ss(s);
    ss >> v >> k;
    mp[k] = v;
  }

  while (cin >> k) {
    cout << (mp.count(k) ? mp[k] : "eh") << "\n";
  }
  return 0;
}