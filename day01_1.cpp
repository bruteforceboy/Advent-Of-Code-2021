#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  int previous = -1, result = 0, measure;
  while (cin >> measure) {
    if (measure > previous && previous != -1) {
      ++result;
    }
    previous = measure;
  }

  cout << result << '\n';

  return 0;
}