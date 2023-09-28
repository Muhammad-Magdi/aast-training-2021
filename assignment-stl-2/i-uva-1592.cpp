#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

int n, m;
map<int, map<string, set<int>>> mp;

void reset() {
  mp.clear();
}

vector<string> takeRow() {
  vector<string> ret;
  string s;
  while (ret.size() < m) {
    getline(cin, s);
    stringstream ss(s);
    while (getline(ss, s, ',') && ret.size() < m) {
      ret.push_back(s);
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  while (cin >> n >> m) {
    cin.ignore();
    reset();

    bool valid = true;
    for (int row = 0; row < n; row++) {
      vector<string> columns = takeRow();
      map<int, int> equal_column;

      for (int column = 0; valid && column < m; column++) {
        string column_value = columns[column];

        if (row && mp[column].count(column_value)) {
          set<int> equal_rows = mp[column][column_value];
          for (int equal_row : equal_rows) {
            if (equal_column.count(equal_row)) {
              printf("NO\n%d %d\n%d %d\n", equal_row + 1, row + 1, equal_column[equal_row] + 1, column + 1);
              valid = false;
              break;
            }
            equal_column[equal_row] = column;
          }
        }

        mp[column][column_value].insert(row);
      }
    }
    if (valid) puts("YES");
  }
  return 0;
}