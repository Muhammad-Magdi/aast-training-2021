#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5, M = 2e5 + 5;

int t, n, m, queryType, u, v;

int leader[N];
int sz[N];
void init()
{
    for (int i = 0; i <= n; i++) {
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

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        init();
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            makeFriends(u, v);
        }
        printf("%d\n", *max_element(sz + 1, sz + n + 1));
    }
    return 0;
}

/*
Samples:
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 1
1 2
9 10
8 9
*/