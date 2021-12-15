#include <bits/stdc++.h>
using namespace std;

// dijkstra on grid? 

int main() {
  
  freopen("input.txt", "r", stdin);

  string s;
  vector<string> grid;
  while (cin >> s) 
    grid.push_back(s);

  int n = (int) grid.size(), m = (int) grid[0].size();
  const int INF = 1e9;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 2e9));
  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.emplace(0, 0);
  dp[0][0] = 0;
  while (!q.empty()) {
    auto [_, pt] = q.top();
    int x = pt / m, y = pt % m;
    q.pop();
    if (vis[x][y]) {
      continue;
    }
    vis[x][y] = true;
    const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
    const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
    
    auto in = [&](int x, int y) {
      return (x >= 0 && x < n && y >= 0 && y < m);  
    };

    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      if (in(nx, ny) && !vis[nx][ny]) {
        dp[nx][ny] = min(dp[nx][ny], (grid[nx][ny] - '0') + dp[x][y]);
        q.emplace(dp[nx][ny], nx * m + ny);
      }
    }
  }

  cout << dp[n - 1][m - 1] << '\n';
  return 0;
}