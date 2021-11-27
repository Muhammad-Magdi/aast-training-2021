#include <bits/stdc++.h>

using namespace std;

const int NO_SOLUTIONS = 0, ONE_SOLUTION = 1, MORE_SOLUTIONS = 2;

const int N = 1e3 + 5, M = 5e4 + 5, OO = 0x3f3f3f3f;

vector<int> adj[N];
int n, m, d, u;
int IN[N];
// int vis[N], testCase;

int BFS() {
  int cnt = 0;
  bool haveOptions = false;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (IN[i] == 0) {
      q.push(i);
      // vis[i] = testCase;
    }
  }

  while (!q.empty()) {
    if (q.size() > 1) haveOptions = true;
    int u = q.front();
    cnt++;
    q.pop();
    for (int v : adj[u]) {
      IN[v]--;
      if (IN[v] == 0 /*&& vis[v] != testCase*/) {
        q.push(v);
        // vis[v] = testCase;
      }
    }
  }
  if (cnt != n)   return NO_SOLUTIONS;
  if (haveOptions)    return MORE_SOLUTIONS;
  return ONE_SOLUTION;
}

void reset() {
  for (int i = 1; i <= n; i++) adj[i].clear();
  // memset(vis, false, sizeof vis);
  // testCase++;
  memset(IN, 0, sizeof IN);
}

int main() {
  while (scanf("%d %d", &n, &m), n || m) {
    reset();
    for (int i = 0; i < m; i++) {
      scanf("%d %d", &d, &u);
      adj[d].push_back(u);
      IN[u]++;
    }
    printf("%d\n", BFS());
  }
  return 0;
}

/*
Sample input:
5 4
1 5
5 2
3 2
4 3
5 4
3 1
4 2
1 5
5 4
2 2
1 2
2 1
0 0
*/