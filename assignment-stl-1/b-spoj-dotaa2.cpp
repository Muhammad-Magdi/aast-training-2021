#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5, M = 20;

struct Hero {
  char name[M];
  int accuracy;
  int speed;
  int stupidity;
};

bool cmp(const Hero& a, const Hero& b) {
  if (a.accuracy != b.accuracy) return a.accuracy > b.accuracy;
  if (a.speed != b.speed) return a.speed > b.speed;
  if (a.stupidity != b.stupidity) return a.stupidity < b.stupidity;
  return strcmp(a.name, b.name) < 0;
}

int n;
Hero heroes[N];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s %d %d %d", heroes[i].name, &heroes[i].accuracy, &heroes[i].speed, &heroes[i].stupidity);
  }

  sort(heroes, heroes + n, cmp);

  for (int i = 0; i < n; i++) {
    printf("%s\n", heroes[i].name);
  }
}