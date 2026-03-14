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
  std::vector<int> k(n), s(n);
  std::vector dp(n + 1, std::vector<int>(m + 1));
  for (int i = 0; i < n; ++i) {
    std::cin >> k[i] >> s[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - k[i - 1] >= 0) {
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k[i - 1]] + s[i - 1]);
      }
    }
  }
  std::println("{}", dp[n][m]);
}