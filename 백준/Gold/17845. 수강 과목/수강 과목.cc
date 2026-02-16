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
  int n, k;
  std::cin >> n >> k;
  std::vector<int> I(k + 1), T(k + 1);
  for (int i = 1; i <= k; ++i) {
    std::cin >> I[i] >> T[i];
  }

  std::vector dp(k + 1, std::vector<int>(n + 1));

  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - T[i] >= 0) dp[i][j] = std::max(dp[i][j], dp[i - 1][j - T[i]] + I[i]);
    }
  }

  std::cout << dp[k][n] << "\n";
}