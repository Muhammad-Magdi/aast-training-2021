#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, M = 2e5 + 5;

int n, q, queryType, u, v;

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
    scanf("%d %d", &n, &q);
    init();
    while (q--) {
        scanf("%d %d %d", &queryType, &u, &v);
        if (queryType == 1) { // Make u, v friends
            makeFriends(u, v);
        } else { // Are u, v friends?
            puts(areFriends(u, v) ? "YES" : "NO");
        }
    }
    return 0;
}

/*
Samples:

*/