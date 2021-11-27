#include <bits/stdc++.h>

using namespace std;
const int N = 10;

int n, solutions;
char grid[N][N];

bool isValid(int r, int c) {
  for (int r2 = r - 1, c2 = c - 1; r2 >= 0 && c2 >= 0; r2--, c2--)
    if (grid[r2][c2] == 'Q')    return false;
  for (int r2 = r - 1, c2 = c + 1; r2 >= 0 && c2 < n; r2--, c2++)
    if (grid[r2][c2] == 'Q')    return false;
  for (int r2 = r - 1; r2 >= 0; r2--)
    if (grid[r2][c] == 'Q')    return false;
  return true;
}

void solve(int r) {
  if (r == n) {       // Done
    solutions++;
    // Print Solution
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%c %c ", grid[i][j], "|\n"[j + 1 == n]);
      }
      puts("--------------------");
    }
    puts("***************************************************");
    return;
  }
  for (int c = 0; c < n; c++) {   // Foreach option
    if (isValid(r, c)) {        // is valid
      grid[r][c] = 'Q';       // Do
      solve(r + 1);             // Recurse
      grid[r][c] = '.';       // Undo
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)  fill(grid[i], grid[i] + n, '.');
  solve(0);
  printf("%d\n", solutions);
  return 0;
}