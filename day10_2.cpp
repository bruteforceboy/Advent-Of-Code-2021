#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  
  freopen("input.txt", "r", stdin);

  string s;
  map<char, int> cnt;
  cnt[')'] = 1, cnt[']'] = 2, cnt['}'] = 3, cnt['>'] = 4;

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

  auto opp = [&](char ch) {
    if (ch == '[') return ']';
    if (ch == '{') return '}';
    if (ch == '<') return '>';
    if (ch == '(') return ')';
  };

  vector<int> values;

  while (cin >> s) {
    int n = (int) s.length();
    vector<char> st;
    bool incomplete = true;
    for (int i = 0; i < n; i++) {
      if (open(s[i])) {
        st.push_back(s[i]);
      } else {
        if (st.empty() || !match(s[i], st.back())) {
          incomplete = false;
        } else {
          st.pop_back();
        }
      }
    }

    incomplete &= (!st.empty());

    if (incomplete) { 

      int cur = 0;
      while (!st.empty()) {
        cur = cur * 5 + cnt[opp(st.back())];
        st.pop_back();
      }

      values.push_back(cur);
    }
  }

  sort(values.begin(), values.end());

  int sz = (int) values.size();
  cout << values[(sz >> 1)];

  return 0;
}