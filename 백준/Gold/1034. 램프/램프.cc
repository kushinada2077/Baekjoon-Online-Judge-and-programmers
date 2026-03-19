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
  std::vector a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      std::cin >> c;
      a[i][j] = c - '0';
    }
  }
  int k;
  std::cin >> k;

  int ans = 0;
  for (int l = 0; l < n; ++l) {
    auto b = a;
    int kk = k;
    for (int i = 0; i < m && kk > 0; ++i) {
      if (b[l][i] == 0) {
        kk--;
        [&]() {
          for (int j = 0; j < n; ++j) {
            b[j][i] ^= 1;
          }
        }();
      }
    }

    if (kk % 2) {
      continue;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += [&]() -> int {
        for (int j = 0; j < m; ++j) {
          if (b[i][j] == 0) {
            return 0;
          }
        }

        return 1;
      }();
    }
    ans = std::max(ans, cnt);
  }
  std::println("{}", ans);
}