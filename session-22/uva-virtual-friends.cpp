#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 2e1 + 5;

int t, n, m, queryType;
char u[M], v[M];

int leader[N];
int sz[N];
void init()
{
    for (int i = 0; i < N; i++) {
        leader[i] = i;
        sz[i] = 1;
    }
}

int getLeader(int u) // O(n)
{
    if (u == leader[u])
        return u;
    return leader[u] = getLeader(leader[u]);
}

bool areFriends(int u, int v)
{
    return getLeader(u) == getLeader(v);
}

void makeFriends(int u, int v)
{
    u = getLeader(u);
    v = getLeader(v);
    if (u == v)
        return;

    leader[u] = v;
    sz[v] += sz[u];
}

int nextId = 1;
map<string, int> id;
int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &m);
        init();
        id.clear();
        nextId = 1;

        for (int i = 0; i < m; i++) {
            scanf("%s %s", u, v);
            if (id[u] == 0)
                id[u] = nextId++;
            if (id[v] == 0)
                id[v] = nextId++;

            makeFriends(id[u], id[v]);
            printf("%d\n", sz[getLeader(id[u])]);
        }
    }
    return 0;
}

/*
Samples:
1
3
Fred Barney
Barney Betty
Betty Wilma
*/