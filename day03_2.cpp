#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  vector<string> inp;
  string s;
  while (cin >> s) {
    inp.push_back(s);
  } 

  int inp_len = (int) inp.size(), rep_len = (int) inp[0].size();
  vector<int> dec(inp_len);
  for (int i = 0; i < inp_len; i++) {
    dec[i] = 0;
    for (int j = 0; j < rep_len; j++) {
      dec[i] += ((inp[i][j] - '0') << (rep_len - j - 1));
    }
  }

  vector<bool> removed1(inp_len);
  vector<bool> removed2(inp_len);
  int rem1 = 0, rem2 = 0;

  auto sieve_msb_bit = [&](int bit) {
    int cntOne = 0, rem = 0;
    for (int i = 0; i < inp_len; i++) 
      if (!removed1[i]) 
        ++rem, cntOne += (inp[i][bit] - '0'); 

    for (int i = 0; i < inp_len; i++) 
      if (!removed1[i]) 
        if ((inp[i][bit] - '0') != (cntOne >= rem - cntOne ? 1 : 0)) 
          removed1[i] = true, ++rem1;

  };

  auto sieve_lsb_bit = [&](int bit) {
    int cntOne = 0, rem = 0;
    for (int i = 0; i < inp_len; i++) 
      if (!removed2[i]) 
        ++rem, cntOne += (inp[i][bit] - '0'); 

    for (int i = 0; i < inp_len; i++) 
      if (!removed2[i]) 
        if ((inp[i][bit] - '0') != (cntOne < rem - cntOne ? 1 : 0)) 
          removed2[i] = true, ++rem2;
  };

  for (int i = 0; i < rep_len; i++) {
    if (rem1 != inp_len - 1) 
      sieve_msb_bit(i);
    if (rem2 != inp_len - 1)
      sieve_lsb_bit(i);
  }

  int ans = 1;

  for (int i = 0; i < inp_len; i++) {
    if (!removed1[i]) {
      ans *= dec[i];
    }
  }

  for (int i = 0; i < inp_len; i++) {
    if (!removed2[i]) {
      ans *= dec[i];
    }
  }
  
  cout << ans << '\n';

  return 0;
}