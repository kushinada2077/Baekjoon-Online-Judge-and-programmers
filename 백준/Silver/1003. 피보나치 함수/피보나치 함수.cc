#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<std::pair<i64, i64>> dp(41);
  dp[0] = {1, 0};
  dp[1] = {0, 1};
  for (int i = 2; i <= 40; ++i) {
    dp[i] = {dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second};
  }
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::cout << dp[n].first << " " << dp[n].second << "\n";
  }
}