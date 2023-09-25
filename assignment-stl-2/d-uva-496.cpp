#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int v;
set<int> s1, s2;
string s;
stringstream ss;

void reset() {
  s1.clear();
  s2.clear();
}

int main() {
  while (getline(cin, s)) {
    reset();

    ss = stringstream(s);
    while (ss >> v) s1.insert(v);

    getline(cin, s);
    ss = stringstream(s);
    while (ss >> v) s2.insert(v);

    bool all_1_in_2 = true, some_1_in_2 = false;
    for (int v : s1) {
      auto itr = s2.find(v);
      if (itr == s2.end()) {
        all_1_in_2 = false;
      } else {
        s2.erase(itr);
        some_1_in_2 = true;
      }
    }

    if (all_1_in_2 && s2.empty()) puts("A equals B");
    else if (all_1_in_2 && !s2.empty()) puts("A is a proper subset of B");
    else if (!all_1_in_2 && s2.empty()) puts("B is a proper subset of A");
    else if (!some_1_in_2) puts("A and B are disjoint");
    else puts("I'm confused!");
  }
  return 0;
}