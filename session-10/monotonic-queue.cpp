#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> q;
deque<int> dq;

void push(int x) {  // O(n) => amortized O(1)
  q.push(x);
  while (!dq.empty() && dq.back() < x) {
    dq.pop_back();
  }
  dq.push_back(x);
}

int pop() { //  O(1)
  if (dq.front() == q.front()) {
    dq.pop_front();
  }
  q.pop();
}

int front() { //  O(1)
  return q.front();
}

int getMax() {  //  O(1)
  return dq.front();
}

int t, x;
string command;



int main() {
  cin >> t;
  while (t--) {
    cin >> command;
    if (command == "push") {
      cin >> x;
      push(x);
    } else if (command == "pop") {
      pop();
    } else if (command == "front") {
      cout << front() << endl;
    } else if (command == "max") {
      cout << getMax() << endl;
    }
  }
  return 0;
}