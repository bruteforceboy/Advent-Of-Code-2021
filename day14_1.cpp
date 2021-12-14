#include <bits/stdc++.h>
using namespace std;

int N = 10;

int main() {
  freopen("input.txt", "r", stdin);

  string s;
  cin >> s;

  map<string, string> mp;

  string a;
  while (cin >> a) {
    string mid; cin >> mid;
    string b;
    cin >> b;
    mp[a] = b;
  }  

  while (N--) {
    string res;
    int n = (int) s.length();
    for (int i = 0; i + 1 < n; i++) {
      string cur;
      cur += s[i];
      cur += s[i + 1];
      res += s[i];
      if (mp.count(cur)) 
        res += mp[cur];
    }
    res += s[n - 1];
    s = res;
  }

  map<char, int> freq;
  for (char c : s) 
    freq[c]++;

  int mn = INT_MAX, mx = INT_MIN;
  for (auto& [x, y] : freq) {
    mn = min(mn, y);
    mx = max(mx, y);
  }

  cout << mx - mn << '\n';
  return 0;
}