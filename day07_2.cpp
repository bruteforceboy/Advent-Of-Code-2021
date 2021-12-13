#include <bits/stdc++.h>
using namespace std;

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
  int n = (int) nums.size();

  long long pt = accumulate(begin(nums), end(nums), 0ll) / n + 1, res = 0;

  auto f = [&](int x) -> long long { return x * (x + 1) >> 1; };

  res = numeric_limits<long long>::max();

  for (int dx = -20; dx <= 20; dx++) { // approx
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      cur += f(abs((pt + dx) - nums[i]));
    }
    res = min(res, cur);
  }

  cout << res << '\n';
  return 0;
}