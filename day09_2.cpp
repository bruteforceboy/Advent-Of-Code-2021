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
  const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    
  vector<pair<int, int>> pts;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool ok = true;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] <= grid[i][j]) {
          ok = false;
        }
      }
      if (ok) {
        pts.emplace_back(i, j);
      }
    }
  }

  vector<vector<bool>> vis(n, vector<bool>(m));
  int res = 1;
  vector<int> sizes;
  for (auto& [x, y] : pts) {
    if (vis[x][y]) {
      continue;
    }

    queue<pair<int, int>> q;
    q.emplace(x, y);
    vis[x][y] = true;
    int sz = 0;
    
    while (!q.empty()) {
      auto [sx, sy] = q.front();
      q.pop();
      ++sz;

      for (int k = 0; k < 4; k++) {
        int nx = sx + dx[k], ny = sy + dy[k];
        auto in = [&](int x, int y) {
          return (x >= 0 && x < n && y >= 0 && y < m);  
        };
        if (in(nx, ny) && !vis[nx][ny] && grid[nx][ny] != '9') {
          vis[nx][ny] = true;
          q.emplace(nx, ny); 
        }
      }
    }

    sizes.push_back(sz);

    res = (res * sz);
  }

  sort(sizes.rbegin(), sizes.rend());
  cout << 1ll * sizes[0] * sizes[1] * sizes[2];
  return 0;
}