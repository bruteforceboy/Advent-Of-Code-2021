#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  vector<string> inp;
  string s;
  while (cin >> s) {
    inp.push_back(s);
  } 

  int rep_len = inp[0].size();
  vector<int> cnt(rep_len);
  for (auto& str : inp) {
    for (int i = 0; i < rep_len; i++) {
      cnt[i] += (str[i] - '0');
    }
  }

  int res1 = 0, res2 = 0;

  for (int i = 0; i < rep_len; i++) {
    if (cnt[i] >= (int) inp.size() / 2) {
      res1 += (1ll << (rep_len - i - 1));
    } else {
      res2 += (1ll << (rep_len - i - 1));
    }
  }

  cout << res1 * res2 << '\n';

  return 0;
}