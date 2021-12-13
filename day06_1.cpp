#include <bits/stdc++.h>
using namespace std;

const int DAYS = 80;
const int N = 9;

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
  vector<long long> cnt(N);
  for (const int& p : nums) 
    cnt[p]++;

  for (int i = 0; i < DAYS; i++) {
    vector<long long> new_cnt(N);

    for (int i = 0; i <= 8; i++) {
      if (i == 8) 
        new_cnt[i] += cnt[0];
      else if (i == 6) 
        new_cnt[i] = cnt[0] + cnt[i + 1];
      else 
        new_cnt[i] += cnt[i + 1]; 
    }

    cnt = new_cnt;
  }

  cout << accumulate(begin(cnt), end(cnt), 0ll);
 
  return 0;
}