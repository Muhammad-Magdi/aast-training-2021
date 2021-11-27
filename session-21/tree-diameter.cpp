#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, M = 2e5 + 5;

int n, u, v;

vector<int> adj[N];
bool vis[N];

int farthestNode;
int longestPathLength;

void DFS(int u, int depth) {       // O(n + m)
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) {
      DFS(v, depth + 1);
    }
  }
  if (depth > longestPathLength) {
    farthestNode = u;
    longestPathLength = depth;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1, 0);

  memset(vis, false, sizeof vis);
  longestPathLength = 0;
  DFS(farthestNode, 0);

  printf("%d\n", longestPathLength);
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