#include <cstdio>

using namespace std;

const int N = 26;

int n;
char x;
int freq[N];  // 0 - 25

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c", &x);
    freq[x - 'a']++;
  }
  for (char x = 'a'; x <= 'z'; x++) {
    while (freq[x - 'a']--) {
      printf("%c", x);
    }
  }
  printf("\n");
  return 0;
}