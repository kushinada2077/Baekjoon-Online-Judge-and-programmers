#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  std::cin >> n >> m;
  std::vector board(n, std::vector<i64>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      std::cin >> c;
      board[i][j] = c - '0';
    }
  }

  std::vector pref(n + 1, std::vector<i64>(m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      pref[i + 1][j + 1] = pref[i][j + 1] + (pref[i + 1][j] - pref[i][j]) + board[i][j];
    }
  }

  i64 ans = 0;
  std::vector comb = {P(0, 1), P(0, 2), P(1, 3), P(2, 3)};

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::vector<int> tmp;
      tmp.push_back(pref[i][j]);
      tmp.push_back(pref[i][m] - pref[i][j]);
      tmp.push_back(pref[n][j] - pref[i][j]);
      tmp.push_back(pref[n][m] - pref[n][j] - pref[i][m] + pref[i][j]);
      for (auto [p, q] : comb) {
        i64 res = tmp[p] + tmp[q];
        for (int k = 0; k < 4; ++k) {
          if (k != p && k != q) res *= tmp[k];
        }
        ans = std::max(ans, res);
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      i64 res = pref[i][m] * (pref[j][m] - pref[i][m]) * (pref[n][m] - pref[j][m]);
      ans = std::max(ans, res);
    }
  }

  for (int i = 1; i < m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      i64 res = pref[n][i] * (pref[n][j] - pref[n][i]) * (pref[n][m] - pref[n][j]);
      ans = std::max(ans, res);
    }
  }

  std::cout << ans << "\n";
}