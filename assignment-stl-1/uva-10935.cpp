#include <cstdio>
#include <queue>

using namespace std;

int n;

int main() {
  while (scanf("%d", &n), n) {
    queue<int> q;
    vector<int> discarded;
    for (int i = 1; i <= n; i++) q.push(i);

    while (q.size() > 1) {
      discarded.push_back(q.front());
      q.pop();

      q.push(q.front());
      q.pop();
    }

    printf("Discarded cards:");
    if (discarded.size() == 0) puts("");
    for (int i = 0; i < int(discarded.size()); i++) {
      bool isLast = (i + 1 == int(discarded.size()));
      printf(" %d%c", discarded[i], ",\n"[isLast]);
    }

    printf("Remaining card: %d\n", q.front());
  }
  return 0;
}