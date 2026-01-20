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
  int n;
  std::cin >> n;

  std::vector ans = {"SK", "CY"};
  std::vector d = {1, 3, 4};
  std::vector dp(n + 1, std::vector<int>(2, -1));
  dp[1][0] = 1;
  dp[1][1] = 0;

  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (j == 0) dp[i][j] = 1;
      for (int k = 0; k < 3; ++k) {
        if (i - d[k] > 0) {
          if (j == 0) {
            dp[i][j] = std::min(dp[i][j], dp[i - d[k]][(j + 1) % 2]);
          } else {
            dp[i][j] = std::max(dp[i][j], dp[i - d[k]][(j + 1) % 2]);
          }
        }
      }
    }
  }

  std::cout << ans[dp[n][0]] << "\n";
}