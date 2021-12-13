#include <bits/stdc++.h>
using namespace std;

int main() {
  
  freopen("input.txt", "r", stdin);

  string s;
  map<char, int> cnt;
  cnt[')'] = 3, cnt[']'] = 57, cnt['}'] = 1197, cnt['>'] = 25137;

  auto match = [&](char close, char open) {
    bool ok = (open == '(' && close == ')') ||
              (open == '[' && close == ']') ||
              (open == '{' && close == '}') || 
              (open == '<' && close == '>');
    return ok;
  };

  auto open = [&](char ch) {
    return (ch == '[' || ch == '{' || ch == '<' || ch == '(');
  };

  int res = 0;

  while (cin >> s) {
    int n = (int) s.length();
    vector<char> st;
    for (int i = 0; i < n; i++) {
      if (open(s[i])) {
        st.push_back(s[i]);
      } else {
        if (st.empty() || !match(s[i], st.back())) {
          res += cnt[s[i]];
          break;
        } else {
          st.pop_back();
        }
      }
    }
  }

  cout << res << '\n';

  return 0;
}