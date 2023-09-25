#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int n, u, v;
queue<int> q;
stack<int> st;
priority_queue<int> pq;

void reset() {
  while (!q.empty()) q.pop();
  while (!st.empty()) st.pop();
  while (!pq.empty()) pq.pop();
}


int main() {
  while (~scanf("%d", &n)) {
    reset();
    int is_queue = 1, is_stack = 1, is_pq = 1;
    while (n--) {
      scanf("%d %d", &u, &v);
      if (u == 1) {
        q.push(v);
        pq.push(v);
        st.push(v);
      } else {
        if (!q.empty() && q.front() == v) q.pop();
        else is_queue = 0;

        if (!st.empty() && st.top() == v) st.pop();
        else is_stack = 0;

        if (!pq.empty() && pq.top() == v) pq.pop();
        else is_pq = 0;
      }
    }

    if (is_queue + is_stack + is_pq > 1) puts("not sure");
    else if (is_queue + is_stack + is_pq == 0) puts("impossible");
    else if (is_queue) puts("queue");
    else if (is_stack) puts("stack");
    else puts("priority queue");
  }
  return 0;
}