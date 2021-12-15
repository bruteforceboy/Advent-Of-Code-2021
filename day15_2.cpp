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
  n *= 5;
  m *= 5;
  vector<string> tmp(n);
  for (int i = 0; i < n; i++) {
    tmp[i].resize(m);
    for (int j = 0; j < m; j++) 
      tmp[i][j] = '0';
  }
  for (int i = 0; i < n / 5; i++) 
    for (int j = 0; j < m / 5; j++) 
      tmp[i][j] = grid[i][j];
  grid = tmp;
  for (int i = 0; i < n / 5; i++) {
    for (int j = m / 5; j < m; j += m / 5) {
      for (int k = 0; k < m / 5; k++) {
        if (grid[i][(k + j) - (m / 5)] == '9') 
          grid[i][k + j] = '1';
        else 
          grid[i][k + j] = grid[i][(k + j) - (m / 5)] + 1;  
      }
    }
  }
  for (int i = 0; i < m / 5; i++) {
    for (int j = n / 5; j < n; j += n / 5) {
      for (int k = 0; k < n / 5; k++) {
        if (grid[(k + j) - (n / 5)][i] == '9') 
          grid[(k + j)][i] = '1';
        else 
          grid[(k + j)][i] = grid[(k + j) - (n / 5)][i] + 1;  
      }
    }
  }
  for (int i = 1; i * (n / 5) < n; i++) {
    for (int j = 1; j * (m / 5) < m; j++) {
      for (int x = 0; x < n / 5; x++) {
        for (int y = 0; y < m / 5; y++) {
          if (grid[i * n / 5 + x - n / 5][j * m / 5 + y] == '9') {
            grid[(i * n / 5) + x][j * (m / 5) + y] = '1';  
          } else {
            grid[(i * n / 5) + x][j * (m / 5) + y] = grid[i * n / 5 + x - n / 5][j * m / 5 + y] + 1;
          }
        }
      }
    }
  }
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