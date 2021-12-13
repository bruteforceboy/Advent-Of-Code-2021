#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  string dir;
  int x = 0, y = 0;
  while (cin >> dir) {
    int delta;
    cin >> delta;

    if (dir == "forward") {
      x += delta;
    } else if (dir == "down") {
      y += delta;
    } else {
      y -= delta;
    }
  }

  cout << x * y << '\n';

  return 0;
}