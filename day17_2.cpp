#include <bits/stdc++.h>
using namespace std;

// brute?

int main() {

  freopen("input.txt", "r", stdin);

  string s;
  getline(cin, s);

  int x1 = stoi(s.substr(s.find('=') + 1, s.find('.')));
  int x2 = stoi(s.substr(s.find('.') + 2, s.find(',')));
  int y1 = stoi(s.substr(s.rfind('=') + 1, s.rfind('.')));
  int y2 = stoi(s.substr(s.rfind('.') + 1));

  int res = 0;

  for (int dx = -1000; dx <= 1000; dx++) {
    for (int dy = -1000; dy <= 1000; dy++) {
      int x = 0, y = 0, xx = dx, yy = dy;
      for (int moves = 0; moves <= 500; moves++) {
        x += yy;
        y += xx;
        if (x >= y1 && x <= y2 && y >= x1 && y <= x2) {
          ++res;
          break;
        }
        if (xx < 0) 
          ++xx;
        else if (xx > 0) 
          --xx;
        --yy;
      }
    }
  }

  cout << res << '\n';
  return 0;
}