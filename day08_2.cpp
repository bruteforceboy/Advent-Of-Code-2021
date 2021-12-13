#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 10, M = 4;

int solve(vector<string>& in, vector<string>& out) {
  
  int res = 0;

  vector<string> rep = {"abcefg", "cf", "acdeg", "acfdg",
                        "bcdf", "abdfg", "abdefg", "acf", "abcdefg", "abcdfg"
                       };
  for (int i = 0; i < N; i++) 
    sort(begin(in[i]), end(in[i]));
  sort(begin(in), end(in));

  vector<string> tmp(in);

  for (int i = 0; i < N; i++) {
    int n = (int) in[i].length();
    if (n == 7) {
      string cur = rep[8];

      do { 
        vector<int> mp(256);

        for (int j = 0; j < 7; j++) {
          mp[cur[j]] = in[i][j] - '0';
        }

        vector<string> new_rep(N);
        for (int i = 0; i < N; i++) {
          new_rep[i] = rep[i];
          for (char& c : new_rep[i]) 
            c = (char) (mp[c] + '0');
          sort(new_rep[i].begin(), new_rep[i].end());
        }

        sort(begin(new_rep), end(new_rep));

        if (new_rep == tmp) {
          int res = 0;
          for (string& str : out) {
            sort(begin(str), end(str));
            for (int i = 0; i < N; i++) {
              string tmp = rep[i];
              for (char& c : tmp) 
                c = (char) (mp[c] + '0');
              sort(begin(tmp), end(tmp));
              if (tmp == str) 
                res = res * 10 + i;
            }
          }
          return res;
        }
      } while (next_permutation(begin(in[i]), end(in[i])));
    }
  }
}

int32_t main() {

  freopen("input.txt", "r", stdin);

  string s;
  vector<string> in, out;
  int res = 0;
  while (cin >> s) {
    in.clear();
    out.clear();
    
    in.push_back(s);
    for (int i = 0; i < N - 1; i++) {
      cin >> s;
      in.push_back(s);
    }

    char ch; cin >> ch;

    for (int i = 0; i < M; i++) {
      cin >> s;
      out.push_back(s);
    }

    res += solve(in, out);
  }

  cout << res << '\n';

  return 0;
}