#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define FROM first
#define TO second

const int N = 1e5 + 5;

int n;
int capacity[2*N]; //...
pair<int, int> A[N];
map<int, int> newHour;
int nxt = 1;

int main() {    // O(n + MAX_DAY_LENGTH)
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &A[i].FROM, &A[i].TO);
    newHour[A[i].FROM];
    newHour[A[i].TO+1];
  }
  for (pair<int, int> p : newHour) {
    newHour[p.first] = nxt++;
  }
  for (int i = 0; i < n; i++) {
    int l = newHour[A[i].FROM];
    int r = newHour[A[i].TO + 1];
    capacity[l]++;
    capacity[r]--;
  }
  for (int i = 1; i < 2*N; i++) {  // ..
    capacity[i] += capacity[i-1];
  }
  printf("%d\n", *max_element(capacity, capacity+2*N));  // ..
  return 0;
}