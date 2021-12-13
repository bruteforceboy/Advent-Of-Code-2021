#include <bits/stdc++.h>
using namespace std;

int main() {

  freopen("input.txt", "r", stdin);

  string s;
  vector<string> in, out;
  int res = 0;
  while (cin >> s) {
    for (int i = 0; i < 9; i++) {
      cin >> s;
    }
    char ch; cin >> ch;
    for (int i = 0; i < 4; i++) {
      cin >> s;
      int n = (int) s.length();
      res += (n == 7 || n == 2 || n == 3 || n == 4);
    }
  }

  cout << res << '\n';

  return 0;
}