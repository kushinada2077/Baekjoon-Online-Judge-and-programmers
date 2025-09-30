#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<P> ac(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> ac[i].first;
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> ac[i].second;
  }

  const int MAX = 10001;
  std::vector dp(n, std::vector<int>(MAX, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < MAX; ++j) {
      if (i - 1 >= 0) dp[i][j] = dp[i - 1][j];
      if (j - ac[i].second >= 0) dp[i][j] = std::max(dp[i][j], (i == 0 ? 0 : dp[i - 1][j - ac[i].second]) + ac[i].first);
    }
  }

  int ans = 0x3f3f3f3f;
  for (int j = 0; j < MAX; ++j) {
    if (dp[n - 1][j] != 0 && dp[n - 1][j] >= m) {
      std::cout << j << "\n";
      break;
    }
  }
}