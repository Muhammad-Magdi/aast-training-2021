#include <iostream>
#include <stack>

using namespace std;

int n;
string s;

int main() {
  cin >> n;
  cin.ignore();

  for (int i = 0; i < n; i++) {
    getline(cin, s);
    stack<char> st;
    bool valid = true;

    for (char c : s) {
      if (c == '[' || c == '(') {
        st.push(c);
      } else if (!st.empty() && ((st.top() == '[' && c == ']') || (st.top() == '(' && c == ')'))) {
        st.pop();
      } else {
        valid = false;
        break;
      }
    }

    if (valid && st.empty()) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}