#include <iostream>
#include <stack>

using namespace std;

int t;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  cin.ignore();

  while (t--) {
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

    if (valid && st.empty())  cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}