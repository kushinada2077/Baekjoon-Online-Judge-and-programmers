#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, ans = 1;
  std::cin >> n >> m;
  std::vector<int> a(m + 1, 0), dp(n + 5, 0);
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i + 1];
  }
  a.push_back(n + 1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  for (int i = 1; i < m + 2; ++i) {
    ans *= dp[a[i] - a[i - 1] - 1];
  }
  std::cout << ans << "\n";
}