#include <cstdio>
#include <queue>

using namespace std;

struct MonotonicQueue {
  queue<int> q;
  deque<int> dq;

  void push(int x) {
    q.push(x);
    while (!dq.empty() && dq.back() < x) {
      dq.pop_back();
    }
    dq.push_back(x);
  }

  void pop() {
    if (dq.front() == q.front()) {
      dq.pop_front();
    }
    q.pop();
  }

  int front() {
    return q.front();
  }

  int max() {
    return dq.front();
  }

  bool empty() {
    return q.empty();
  }

  int size() {
    return q.size();
  }
};

int t, n, k, x;

int main() {
  // cin >> t;
  scanf("%d", &t);
  while (t--) {
    // cin >> n >> k;
    scanf("%d %d", &n, &k);
    MonotonicQueue mq;
    for (int i = 0; i < n; i++) {
      // cin >> x;
      scanf("%d", &x);
      if (i < k) {
        mq.push(x);
      } else {
        // cout << mq.max() << " ";
        printf("%d ", mq.max());
        mq.pop();
        mq.push(x);
      }
    }
    // cout << mq.max() << endl;
    printf("%d\n", mq.max());
  }
  return 0;
}