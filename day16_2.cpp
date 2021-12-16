#include <bits/stdc++.h>
using namespace std;

#define int long long

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

int32_t main() {

  freopen("input.txt", "r", stdin);

  string s;
  cin >> s;

  string val = hex_to_bin(s);
  int sz = (int) val.length();

  int cur_idx = 0;

  function<int()> solve = [&]() {

    int version = bin_to_dec(val.substr(cur_idx, 3));
    cur_idx += 3;

    int type = bin_to_dec(val.substr(cur_idx, 3));
    cur_idx += 3;

    auto eval = [&](vector<int> values) -> long long {
      if (type == 0) 
        return accumulate(begin(values), end(values), 0ll);
      else if (type == 1) 
        return accumulate(begin(values), end(values), 1ll, multiplies<int>{});
      else if (type == 2) 
        return *min_element(begin(values), end(values));
      else if (type == 3) 
        return *max_element(begin(values), end(values));
      else {
        if (type == 5) return values[0] > values[1];
        else if (type == 6) return values[0] < values[1];
        else return values[0] == values[1];
      }
    };

    int ret = 0;

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

      ret = bin_to_dec(bin);

    } else {
      string bin;
      int len;
      if (val[cur_idx] == '0') {
        len = bin_to_dec(val.substr(cur_idx + 1, 15));
        cur_idx += 16;

        vector<int> values;
        int tmp = cur_idx;
        while (cur_idx < tmp + len) {
          values.push_back(solve());
        }
        ret = eval(values);
      } else {
        len = bin_to_dec(val.substr(cur_idx + 1, 11));
        cur_idx += 12;

        vector<int> values;
        for (int i = 0; i < len; i++) {
          values.push_back(solve());
        }
        ret = eval(values);
      }
    }

    return ret;
  };

  cout << solve() << '\n';
  return 0;
}