#include <bits/stdc++.h>
using i64 = long long;

constexpr int M = 1e9 + 9;
void solve(std::vector<i64>& dp) {
  int n;
  std::cin >> n;
  std::cout << dp[n] << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  std::vector<i64> dp(1000001);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i <= 1000000; ++i) {
    dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % M;
  }
  while (t--) {
    solve(dp);
  }
}