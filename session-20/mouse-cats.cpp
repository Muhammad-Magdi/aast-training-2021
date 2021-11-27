#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, M = 1e3 + 5, OO = 0x3f3f3f3f;

int n, m, mR, mC;
char grid[N][M];

bool isValid(int r, int c) {
  return r < n&& r >= 0 && c < m&& c >= 0;
}

int dR[] = { 1, -1, 0, 0 };
int dC[] = { 0, 0, 1, -1 };
int catDis[N][M];
void BFSCats() {
  memset(catDis, OO, sizeof catDis);

  queue <pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'C') {
        q.push({ i, j });
        catDis[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int nR = u.first + dR[k];
      int nC = u.second + dC[k];
      if (isValid(nR, nC) && catDis[nR][nC] == OO && grid[nR][nC] != '#') {
        catDis[nR][nC] = catDis[u.first][u.second] + 1;
        q.push({ nR, nC });
      }
    }
  }
}

pair<int, int> parent[N][M];
pair<int, int> ext;
int mouseDis[N][M];
bool BFSMouse(int mR, int mC) {
  memset(mouseDis, OO, sizeof mouseDis);

  queue <pair<int, int>> q;
  q.push({ mR, mC });
  mouseDis[mR][mC] = 0;

  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int nR = u.first + dR[k];
      int nC = u.second + dC[k];
      if (isValid(nR, nC) && mouseDis[nR][nC] == OO && grid[nR][nC] != '#' && catDis[nR][nC] > mouseDis[u.first][u.second] + 1) {
        parent[nR][nC] = u;
        if (grid[nR][nC] == 'E') {
          ext = { nR, nC };
          return true;
        }

        mouseDis[nR][nC] = mouseDis[u.first][u.second] + 1;
        q.push({ nR, nC });
      }
    }
  }
  return false;
}

void printPath(int r, int c) {
  if (r == mR && c == mC) {
    printf("%d %d\n", r, c);
    return;
  }
  printPath(parent[r][c].first, parent[r][c].second);
  printf("%d %d\n", r, c);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", grid[i]);
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'M') {
        mR = i;
        mC = j;
      }
    }
  }
  BFSCats();
  bool canEscape = BFSMouse(mR, mC);
  puts(BFSMouse(mR, mC) ? "YES" : "NO");
  if (canEscape) printPath(ext.first, ext.second);
  return 0;
}

/*
5 5
E--E-
-C#-#
-#---
C-M-E
-----
*/