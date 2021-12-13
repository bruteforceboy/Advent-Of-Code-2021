#include <bits/stdc++.h>
using namespace std;

int main() {

  freopen("input.txt", "r", stdin);

  string s;
  vector<string> grid;
  while (cin >> s) {
    grid.push_back(s);
  }

  int n = (int) grid.size(), m = (int) grid[0].size();
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
      bool ok = true;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] <= grid[i][j]) {
          ok = false;
        }
      }
      if (ok) {
        res += grid[i][j] - '0' + 1;
      }
    }
  }

  cout << res << '\n';
  return 0;
}