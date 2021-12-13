#include <bits/stdc++.h>
using namespace std;

const int n = 5;

vector<int> readList() {
  string s;
  cin >> s; 
  vector<int> nums;
  int cur = 0;
  for (int i = 0; i < (int) s.length(); i++) {
    if (s[i] != ',') {
      cur = cur * 10 + (s[i] - '0');
    } else {
      nums.push_back(cur);
      cur = 0;
    }
  }
  nums.push_back(cur);
  return nums;
} 

int main() {

  freopen("input.txt", "r", stdin);
  
  vector<int> nums = readList();
  vector<vector<vector<int>>> grids;

  int x;
  while (cin >> x) {
    vector<vector<int>> grid(n, vector<int>(n));
    grid[0][0] = x;
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < n; j++) 
        if (i + j > 0) 
          cin >> grid[i][j];
    grids.push_back(grid);
  }

  int sz = (int) grids.size();

  auto play = [&](int idx, int cur) {
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < n; j++) 
        if (grids[idx][i][j] == cur) 
          grids[idx][i][j] = -1;

    bool ok = true;
    for (int i = 0; i < n; i++) {
      bool ok1 = true, ok2 = true;
      for (int j = 0; j < n; j++) {
        ok1 &= (grids[idx][i][j] == -1);
        ok2 &= (grids[idx][j][i] == -1);
      }
      if (ok1 || ok2) {
        int sum = 0;
        for (int i = 0; i < n; i++) 
          for (int j = 0; j < n; j++) 
            if (grids[idx][i][j] != -1) 
              sum += grids[idx][i][j];
        cout << sum * cur << '\n';
        return true;
      }
    }

    return false;
  };

  for (const int& num : nums) 
    for (int i = 0; i < sz; i++)
      if (play(i, num)) 
        return 0;

  return 0;
}