#include <iostream>
#include <stack>

using namespace std;

string s;
stack<char> st;

int main() {
  cin >> s;
  for (char c : s) {
    if (c == '(' || c == '[') {
      st.push(c);
    } else if (c == ']') {
      if (!st.empty() && st.top() == '[') {
        st.pop();
      } else {
        cout << "NO" << endl;
        return 0;
      }
    } else if (c == ')') {
      if (!st.empty() && st.top() == '(') {
        st.pop();
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  if (st.empty()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}