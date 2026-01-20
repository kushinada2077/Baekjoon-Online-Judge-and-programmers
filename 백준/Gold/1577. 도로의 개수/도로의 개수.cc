#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
using F = std::tuple<int, int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m, k;
  std::cin >> m >> n >> k;
  std::set<F> blocked;
  for (int i = 0; i < k; ++i) {
    int a, b, c, d;
    std::cin >> b >> a >> d >> c;
    blocked.insert({a, b, c, d});
    blocked.insert({c, d, a, b});
  }

  std::vector dp(n + 1, std::vector<i64>(m + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      i64 new_val = 0;
      if (i > 0 && !blocked.contains({i, j, i - 1, j})) new_val += dp[i - 1][j];
      if (j > 0 && !blocked.contains({i, j, i, j - 1})) new_val += dp[i][j - 1];
      dp[i][j] = std::max(dp[i][j], new_val);
    }
  }

  std::cout << dp[n][m] << "\n";
}