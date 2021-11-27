#include <iostream>
#include <map>

using namespace std;

const int N = 1e5 + 5;

int n, q;
int prefix[N];   // prefix sum array

int main() {    // O(n + q)
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", prefix + i);
    prefix[i] += prefix[i - 1]; // Preprocessing
    cout << prefix[i] << endl;
  }
  while (q--) {
    // int l, r;
    // scanf("%d %d", &l, &r);
    // int sum = 0;
    // for (int i = l; i <= r; i++) {
    //   sum += A[i];
    // }

    // int x;
    // scanf("%d", &x);
    // printf("%d\n", prefix[x]);

    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", prefix[r] - prefix[l - 1]);
  }
  return 0;
}