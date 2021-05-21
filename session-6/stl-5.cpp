#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n, x;

int main() {
  while(cin >> n, n) {  // number of test cases
    queue<int> q;
    for (int i = 0; i < n; i++) {
      cin >> x;
      q.push(x);
    }
    stack<int> st;
    int next = 1;
    while (!q.empty() || (!st.empty() && st.top() == next)) {
      if (!q.empty() && q.front() == next) {
        q.pop();
        next++;
      } else if (!st.empty() && st.top() == next) {
        st.pop();
        next++;  
      } else if (!q.empty()) {
        st.push(q.front());
        q.pop();
      }
    }
    if (next == n + 1) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }  
  return 0;
}