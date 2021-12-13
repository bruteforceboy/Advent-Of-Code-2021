#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  int x1, y1, x2, y2; char ch;
  vector<pair<int, int>> start, end;

  int mx = 0;
  while (cin >> x1) {
    cin >> ch >> y1 >> ch >> ch >> x2 >> ch >> y2;
    start.emplace_back(x1, y1);
    end.emplace_back(x2, y2);
    mx = max(mx, max({x1, y1, x2, y2}));
  }

  vector<vector<int>> grid(mx + 1, vector<int>(mx + 1));

  int sz = (int) start.size();
  for (int i = 0; i < sz; i++) {
    auto [x1, y1] = start[i];
    auto [x2, y2] = end[i];
    int dx = abs(x1 - x2), dy = abs(y1 - y2);
    if (dx == dy) {
      for (int i = 0; i < dx; i++) {
        grid[x1][y1]++;
        if (x1 < x2) ++x1;
        else --x1;

        if (y1 < y2) ++y1;
        else --y1;
      }
      grid[x1][y1]++;
    } else if (dy == 0) {
      for (int i = 0; i < dx; i++) {
        grid[x1][y1]++;

        if (x1 < x2) ++x1;
        else --x1;
      }
      grid[x1][y1]++;
    } else if (dx == 0) {
      for (int i = 0; i < dy; i++) {
        grid[x1][y1]++;

        if (y1 < y2) ++y1;
        else --y1;
      }
      grid[x1][y1]++;
    }
  }

  int res = 0;
  for (int i = 0; i <= mx; i++)
    for (int j = 0; j <= mx; j++)
      if (grid[i][j] >= 2)
        ++res;

  cout << res << '\n';
  return 0;
}