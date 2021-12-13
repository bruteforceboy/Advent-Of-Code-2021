#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  string dir;
  int x = 0, y = 0, aim = 0, depth = 0;

  while (cin >> dir) {
    int delta;
    cin >> delta;

    if (dir == "forward") {
      x += delta;
      depth += aim * delta;
    } else if (dir == "down") {
      aim += delta;
    } else {
      aim -= delta;
    }
  }

  cout << 1ll * depth * x << '\n';

  return 0;
}