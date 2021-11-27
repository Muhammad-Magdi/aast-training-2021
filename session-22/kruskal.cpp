#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5, M = 1e5 + 5;

#define C first
#define U second.first
#define V second.second
typedef pair<int, pair<int, int>> edge;

int n, m, u, v, c;

int parent[N];
void init()
{
  for (int i = 0; i < N; i++) {
    parent[i] = i;
  }
}

int getRoot(int u) // O(n)
{
  if (u == parent[u])
    return u;
  return parent[u] = getRoot(parent[u]);
}

bool sameSet(int u, int v)
{
  return getRoot(u) == getRoot(v);
}

void merge(int u, int v)
{
  u = getRoot(u);
  v = getRoot(v);
  if (u == v)
    return;

  parent[u] = v;
}

edge edgeList[M];
int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &c);
    edgeList[i] = { c, { u, v } };
  }
  init();

  // Kruskal
  sort(edgeList, edgeList + m);
  int cost = 0;
  for (int i = 0; i < m; i++) {
    if (!sameSet(edgeList[i].U, edgeList[i].V)) {
      merge(edgeList[i].U, edgeList[i].V);
      cost += edgeList[i].C;
    }
  }

  printf("%d\n", cost);
  return 0;
}

/*
Samples:
6 9
1 2 4
1 4 7
1 3 5
2 4 8
2 5 1
2 6 10
3 5 7
4 6 13
5 6 3
*/