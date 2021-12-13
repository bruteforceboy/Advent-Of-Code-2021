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

  sort(begin(nums), end(nums));
  int med = nums[n / 2], res = 0;

  for (int i = 0; i < n; i++) {
    res += abs(med - nums[i]);
  }

  cout << res << '\n';
  return 0;
}