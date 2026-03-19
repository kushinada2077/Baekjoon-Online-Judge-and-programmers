#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using TP = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  std::cin >> n >> m;
  std::vector<int> z(n);
  std::vector<i64> bit(n);
  std::map<i64, int> cnt;
  for (int i = 0; i < n; ++i) {
    i64 x = 0;
    for (int j = 0; j < m; ++j) {
      char c;
      std::cin >> c;
      c -= '0';
      x = x * 2 + c;
      if (c == 0) {
        z[i]++;
      }
    }
    cnt[x]++;
    bit[i] = x;
  }
  int k;
  std::cin >> k;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (k >= z[i] && (k - z[i]) % 2 == 0) {
      ans = std::max(ans, cnt[bit[i]]);
    }
  }
  std::println("{}", ans);
}