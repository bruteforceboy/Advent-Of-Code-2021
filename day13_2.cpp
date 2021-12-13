#include <bits/stdc++.h>
using namespace std;

int main() {

  freopen("input.txt", "r", stdin);

  vector<pair<int, int>> pts;
  vector<pair<string, int>> folds;

  int n = 0, m = 0;

  string s;
  while (getline(cin, s)) {
    if (s.empty()) continue;
    if (s[0] == 'f') {
      folds.emplace_back(s.substr(s.find('=') - 1, 1),
                         stoi(s.substr(s.find('=') + 1)));
    } else {
      int a = stoi(s.substr(0, s.find(',')));
      int b = stoi(s.substr(s.find(',') + 1));
      swap(a, b);
      pts.emplace_back(a, b);
      n = max(n, a);
      m = max(m, b);
    }
  }

  vector<vector<int>> grid(n + 1, vector<int>(m + 1));
  for (auto& [x, y] : pts)
    grid[x][y]++;

  for (auto& [fold, pos] : folds) {
    if (fold == "x") {
      for (int i = 0; i <= n; i++) {
        for (int j = pos; j <= m; j++) {
          int tmp = grid[i][j];
          grid[i][j] = 0;
          if (pos - (j - pos) >= 0)
            grid[i][pos - (j - pos)] += tmp;
        }
      }
      vector<vector<int>> new_grid(n + 1, vector<int>(pos));
      for (int i = 0; i <= n; i++)
        for (int j = 0; j < pos; j++)
          new_grid[i][j] = grid[i][j];
      grid = new_grid;
      m = pos - 1;
    } else {
      for (int i = 0; i <= m; i++) {
        for (int j = pos; j <= n; j++) {
          int tmp = grid[j][i];
          grid[j][i] = 0;
          if (pos - (j - pos) >= 0)
            grid[pos - (j - pos)][i] += tmp;
        }
      }
      vector<vector<int>> new_grid(pos, vector<int>(m + 1));
      for (int i = 0; i < pos; i++)
        for (int j = 0; j <= m; j++)
          new_grid[i][j] = grid[i][j];
      grid = new_grid;
      n = pos - 1;
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (grid[i][j] > 0)
        cout << "#";
      else
        cout << " ";
    }
    cout << '\n'; 
  }

  return 0;
}