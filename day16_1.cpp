#include <bits/stdc++.h>
using namespace std;

int bin_to_dec(string str) {
  reverse(begin(str), end(str));
  int res = 0;
  int pow = 1;
  for (int i = 0; i < (int) str.length(); i++) {
    res += pow * (str[i] - '0');
    pow <<= 1;
  }
  return res;
}

string hex_to_bin(string str) {
  string res;
  vector<string> mp = {"0000", "0001", "0010", "0011",
                       "0100", "0101", "0110", "0111",
                       "1000", "1001", "1010", "1011",
                       "1100", "1101", "1110", "1111"
                      };
  for (int i = 0; i < (int) str.length(); i++) {
    int idx = 0;
    if (str[i] >= 'A' && str[i] <= 'F') idx = str[i] - 'A' + 10;
    else idx = str[i] - '0';
    res += mp[idx];
  }
  return res;
}

int main() {

  freopen("input.txt", "r", stdin);

  string s;
  cin >> s;

  string val = hex_to_bin(s);
  int sz = (int) val.length();

  int cur_idx = 0, res = 0;

  function<void()> solve = [&]() {

    int version = bin_to_dec(val.substr(cur_idx, 3));
    cur_idx += 3;

    int type = bin_to_dec(val.substr(cur_idx, 3));
    cur_idx += 3;

    res += version;

    if (type == 4) {
      string bin;

      while (true) {
        bin += val.substr(cur_idx + 1, 4);
        int stop = val[cur_idx] - '0';
        cur_idx += 5;
        if (stop == 0) {
          break;
        }
      }

      return;

    } else {
      string bin;
      int len;
      if (val[cur_idx] == '0') {
        len = bin_to_dec(val.substr(cur_idx + 1, 15));
        cur_idx += 16;

        int tmp = cur_idx;
        while (cur_idx < tmp + len) {
          solve();
        }

      } else {
        len = bin_to_dec(val.substr(cur_idx + 1, 11));
        cur_idx += 12;

        for (int i = 0; i < len; i++) {
          solve();
        }
      }
    }
  };

  solve();

  cout << res << '\n';
  return 0;
}