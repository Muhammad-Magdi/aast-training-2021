#include <cstdio>
#include <cstring>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

const int N = 1e3 + 3, M = 128;
char str[N];
int freq[M];
set<pair<int, char>> st;  // <Freq, -1 * ASCII>
bool is_first_case = true;

void reset() {
  for (int i = 0; i < M; i++) freq[i] = 0;
  st.clear();
}

int main() {
  while (cin.getline(str, N)) {
    if (!is_first_case) puts("");
    is_first_case = false;

    reset();

    int n = strlen(str);
    for (int i = 0; i < n; i++) {
      freq[str[i]]++;
    }

    for (int i = 0; i < M; i++) {
      if (freq[i]) {
        st.insert({ freq[i], -i });   // The negative sign here to order DESC by the ASCII code
      }
    }

    for (auto it : st) {
      printf("%d %d\n", -it.second, it.first);
    }
  }
  return 0;
}