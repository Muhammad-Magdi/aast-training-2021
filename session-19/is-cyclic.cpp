#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

int n, m, u, v;

vector<int> adj[N];
bool vis[N];

bool isCyclic(int u, int p) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (vis[v] && v != p)   return true;
        else if (!vis[v]) {
            if (isCyclic(v, u)) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    int start;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        start = u;
    }
    puts(m == n-1 && !isCyclic(start, -1) ? "YES" : "NO");
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