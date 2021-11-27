#include<cstdio>
#include <stack>
#include <queue>

using namespace std;

int n, x;

int main() {
  while (scanf("%d", &n), n) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
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

    if (next == n + 1)  printf("yes\n");
    else  printf("no\n");

  }
  return 0;
}