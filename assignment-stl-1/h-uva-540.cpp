#include <cstdio>
#include <queue>

using namespace std;

const int N = 1e6 + 1, M = 1e3 + 2;

typedef long long ll;

int t, n, x, teamID[N];
char query[10];
queue<int> team[M];
queue<int> qK;
int tc;

int main() {
  while (scanf("%d", &t), t) {
    while (!qK.empty())  qK.pop();                   //reset

    printf("Scenario #%d\n", ++tc);
    for (int i = 0; i < t; ++i) {
      while (!team[i].empty()) team[i].pop();      //reset

      scanf("%d", &n);
      for (int j = 0; j < n; ++j) {
        scanf("%d", &x);
        teamID[x] = i;
      }
    }

    while (scanf("%s", query), query[0] != 'S') {
      if (query[0] == 'E') {  // ENQUEUE
        scanf("%d", &x);
        int id = teamID[x];
        if (team[id].size() == 0)    qK.push(id);
        team[id].push(x);
      } else {  // DEQUEUE
        int id = qK.front();
        printf("%d\n", team[id].front());
        team[id].pop();
        if (team[id].size() == 0) qK.pop();
      }
    }
    puts("");
  }
  return 0;
}