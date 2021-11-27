#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int q, n;
string command;
bool isReversed;
// vector<int> v;
deque<int> dq;

int main() {
  cin >> q;
  while (q--) { // O(q^2) -> O(q)
    cin >> command;
    if (command == "back") {  // O(1)
      if (dq.empty()) {
        cout << "No job for Ada?" << endl;
      } else {
        if (isReversed) {
          cout << dq.front() << endl;
          dq.pop_front();
        } else {
          cout << dq.back() << endl;
          dq.pop_back();
        }
      }
    } else if (command == "front") {  // O(q) -> O(1)
      if (dq.empty()) {
        cout << "No job for Ada?" << endl;
      } else {
        if (isReversed) {
          cout << dq.back() << endl;
          dq.pop_back();
        } else {
          cout << dq.front() << endl;
          // v.erase(v.begin());
          dq.pop_front();
        }
      }
    } else if (command == "reverse") {  // O(q) -> O(1)
      // reverse(dq.begin(), dq.end());
      isReversed = !isReversed;
    } else if (command == "push_back") {  // O(1)
      cin >> n;
      if (isReversed) {
        dq.push_front(n);
      } else {
        dq.push_back(n);
      }
    } else { // O(q) -> O(1)
      cin >> n;
      // v.insert(v.begin(), n);
      if (isReversed) {
        dq.push_back(n);
      } else {
        dq.push_front(n);
      }
    }
  }
  return 0;
}