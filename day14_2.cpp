#include <bits/stdc++.h>
using namespace std;

#define int long long

int N = 40;

int32_t main() {
  freopen("input.txt", "r", stdin);

  string s;
  cin >> s;

  map<string, string> mp;

  string a;
  string tmp = s;
  while (cin >> a) {
    string mid; cin >> mid;
    string b;
    cin >> b;
    mp[a] = b;
  }

  int n = (int) s.length();
  map<string, int> cnt;

  for (int i = 0; i + 1 < n; i++) {
    string cur;
    cur += s[i];
    cur += s[i + 1];
    cnt[cur]++;
  }

  while (N--) {
    map<string, int> new_cnt;
    for (auto& [s, x] : cnt) {
      string nxt = mp[s];
      string cur;
      cur += s[0];
      cur += nxt[0];
      new_cnt[cur] += x;
      string cur2;
      cur2 += nxt[0];
      cur2 += s[1];
      new_cnt[cur2] += x;
    }
    cnt = new_cnt;
  }

  map<char, int> freq;
  for (auto& [s, x] : cnt) 
    freq[s[1]] += x;

  freq[tmp[0]]++;

  int mn = numeric_limits<int>::max(), mx = numeric_limits<int>::min();
  for (auto& [x, y] : freq) {
    mn = min(mn, y);
    mx = max(mx, y);
  }

  cout << mx - mn << '\n';
  return 0;
}