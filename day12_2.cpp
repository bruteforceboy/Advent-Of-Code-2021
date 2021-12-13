#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  map<string, vector<string>> adj;

  string s;
  while (cin >> s) {
    int pos = s.find('-');
    string u = s.substr(0, pos), v = s.substr(pos + 1);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int res = 0;

  map<string, bool> vis;

  auto isSmallCave = [&](string s) {
    for (char c : s)
      if (isupper(c)) return false;
    return true;
  };

  auto isBigCave = [&](string s) {
    for (char c : s)
      if (islower(c)) return false;
    return true;
  };

  bool twice = false;
  function<void(string)> solve = [&](string str) -> void {

    for (string to : adj[str]) {
      if (to == "start") continue;
      if (to == "end") 
        ++res;
      else if (isSmallCave(to)) {
        if (vis[to] && !twice) {
          twice = true, solve(to), twice = false;
        } else if (!vis[to]) {
          vis[to] = true, solve(to), vis[to] = false;
        }
      } else if (isBigCave(to)) {
        solve(to);
      }
    }
  };

  solve("start");

  cout << res << '\n';
  return 0;
}