#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  int measure;
  vector<int> values;
  while (cin >> measure) {
    values.push_back(measure);
  }

  vector<int> sums;
  for (int i = 0; i + 2 < (int) values.size(); i++) {
    sums.push_back(values[i] + values[i + 1] + values[i + 2]);
  }

  int res = 0;
  for (int i = 1; i < (int) sums.size(); i++) {
    res += (sums[i] > sums[i - 1]);
  }

  cout << res << '\n';

  return 0;
 }