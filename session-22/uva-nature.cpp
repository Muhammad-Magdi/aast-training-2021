#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5, M = 3e1 + 5;

int n, m;
char u[M], v[M];

int parent[N];
int sz[N];
void init()
{
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        sz[i] = 1;
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
    sz[v] += sz[u];
}

map<string, int> id;
int main()
{
    while (scanf("%d %d", &n, &m), n || m) {
        id.clear();
        init();
        for (int i = 1; i <= n; i++) {
            scanf("%s", u);
            id[u] = i;
        }

        for (int i = 0; i < m; i++) {
            scanf("%s %s", u, v);
            merge(id[u], id[v]);
        }
        printf("%d\n", *max_element(sz + 1, sz + n + 1));
    }
    return 0;
}

/*
Samples:
5 2
caterpillar
bird
horse
elefant
herb
herb caterpillar
caterpillar bird
0 0
*/