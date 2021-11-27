#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

int n, m, u, v;

vector<int> adj[N];
bool vis[N];

void DFS(int u) {       // o(n + m)
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) {
      DFS(v);
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
  return 0;
}

/*
Samples:
7 6
0 1
1 2
2 5
2 3
2 6
3 4
*/