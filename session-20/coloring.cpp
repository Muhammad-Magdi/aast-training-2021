#include <bits/stdc++.h>

using namespace std;

const int NOT_COLORED = 0, RED = 1, BLUE = 2;

const int N = 1e5 + 5, M = 2e5 + 5, OO = 0x3f3f3f3f;

int n, m, u, v;

vector<int> adj[N];

int color[N];
bool isBiColorable(int src) {
  memset(color, NOT_COLORED, sizeof color);
  color[src] = RED;
  queue<int> q;
  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (color[v] == NOT_COLORED) {
        color[v] = (color[u] == RED ? BLUE : RED);
        q.push(v);
      } else if (color[v] == color[u]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  puts(isBiColorable(0) ? "YES" : "NO");
  return 0;
}

/*
Sample input:
8 8
0 1
0 2
0 7
1 3
1 4
2 5
2 6
6 7
*/