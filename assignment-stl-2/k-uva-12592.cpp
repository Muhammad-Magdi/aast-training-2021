#include <iostream>
#include <map>

using namespace std;

int n, q;
string f, s;
map<string, string> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin.ignore();
  while (n--) {
    getline(cin, f);
    getline(cin, s);
    mp[f] = s;
  }

  cin >> q;
  cin.ignore();
  while (q--) {
    getline(cin, f);
    cout << mp[f] << "\n";
  }

  return 0;
}