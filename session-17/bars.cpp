#include <bits/stdc++.h>

using namespace std;
const int N = 10;

int n, target;
int A[N];

int sum;
vector<int> path;
void solve(int i) {
  if (i == n) {
    if (sum == target) {
      for (int i = 0; i < path.size(); i++) {
        printf("%d%c", path[i], " \n"[i + 1 == path.size()]);
      }
    }
    return;
  }
  // Option 1 => Pick
  if (sum + A[i] <= target) {     // Valid
    sum += A[i];    // Do
    path.push_back(A[i]);
    solve(i + 1);     // Recurse
    sum -= A[i];    // Undo
    path.pop_back();
  }
  // Option 2 => Leave
  // Do
  solve(i + 1); // Recurse
  // Undo
}

int main() {
  scanf("%d %d", &n, &target);
  for (int i = 0; i < n; i++) {
    scanf("%d", A + i);
  }
  solve(0);
  return 0;
}
/*
925
10
45 15 120 500 235 58 6 12 175 70
*/