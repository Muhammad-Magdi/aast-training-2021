#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
int n;
pair< string, string > A[109];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    cin >> A[i].first >> A[i].second;

  for (int i = 0; i < n; ++i)
    if (A[i].second[0] == 'r')
      printf("%s\n", A[i].first.c_str());

  for (int i = 0; i < n; ++i)
    if (A[i].second[0] == 'w' || A[i].second[1] == 'h')
      printf("%s\n", A[i].first.c_str());

  for (int i = 0; i < n; ++i)
    if (A[i].second[0] == 'm')
      printf("%s\n", A[i].first.c_str());

  for (int i = 0; i < n; ++i)
    if (A[i].second[2] == 'p')
      printf("%s\n", A[i].first.c_str());

  return 0;
}