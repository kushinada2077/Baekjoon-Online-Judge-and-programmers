#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> dp(k + 1, 0x3f3f3f3f);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    int v;
    std::cin >> v;
    for (int j = 1; j <= k; ++j) {
      if (j - v >= 0) dp[j] = std::min(dp[j], dp[j - v] + 1);
    }
  }

  if (dp[k] == 0x3f3f3f3f) dp[k] = -1;
  std::cout << dp[k] << "\n";
}