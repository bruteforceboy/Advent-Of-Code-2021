#include <bits/stdc++.h>
using namespace std;

int N = 100;

const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

int main() {

  freopen("input.txt", "r", stdin);

  string s;
  vector<string> grid;
  while (cin >> s) {
    grid.push_back(s);
  }

  int n = (int) grid.size(), m = (int) grid[0].size();
  int step = 0;

  while (true) {
    ++step;

    vector<vector<bool>> flashed(n, vector<bool>(m));

    auto nine = [&]() {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == '9' && !flashed[i][j]) {
            return true;
          }
        }
      }
      return false;
    };

    while (nine()) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j] == '9' && !flashed[i][j]) {
            flashed[i][j] = true;
            grid[i][j] = '0';
            for (int k = 0; k < 8; k++) {
              int nx = i + dx[k], ny = j + dy[k];
              auto in = [&](int x, int y) {
                return (x >= 0 && x < n && y >= 0 && y < m);
              };
              if (in(nx, ny)) {
                if (grid[nx][ny] != '9' && !flashed[nx][ny]) {
                  ++grid[nx][ny];
                }
              }
            }
          }
        }
      }
    }

    bool allFlashed = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        allFlashed &= (flashed[i][j]);
      }
    }

    if (allFlashed) {
      cout << step << '\n';
      return 0;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!flashed[i][j] && grid[i][j] != '9') {
          ++grid[i][j];
        }
      }
    }
  }

  return 0;
}