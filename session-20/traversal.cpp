#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5, OO = 0x3f3f3f3f;

int n, m, u, v;

vector<int> adj[N];

int dis[N];
void BFS(int src) { // O(n + m)
  dis[src] = 0;
  queue<int> q;
  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dis[v] == OO) {
        q.push(v);
        dis[v] = dis[u] + 1;
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dis, OO, sizeof dis);
  BFS(0);
  for (int u = 0; u < n; u++) {
    printf("%d %d\n", u, dis[u]);
  }
  return 0;
}

/*
Sample input:
9 13
0 1
0 2
0 3
0 7
1 6
2 6
3 5
7 8
7 6
6 4
5 6
5 8
6 8
*/