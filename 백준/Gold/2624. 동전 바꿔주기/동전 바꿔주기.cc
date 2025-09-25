#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t, k;
  std::cin >> t >> k;
  std::vector<int> p(k), n(k);

  for (int i = 0; i < k; ++i) {
    std::cin >> p[i] >> n[i];
  }

  std::vector dp(k, std::vector<int>(10001, 0));
  for (int i = 0; i <= n[0]; i++) {
    dp[0][i * p[0]] = 1;
  }

  for (int i = 1; i < k; ++i) {
    for (int j = 0; j <= 10000; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - p[i] >= 0) dp[i][j] += dp[i][j - p[i]];
      if (j - p[i] * (n[i] + 1) >= 0) dp[i][j] -= dp[i - 1][j - p[i] * (n[i] + 1)];
    }
  }

  std::cout << dp[k - 1][t] << "\n";
}