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
  int n;
  std::cin >> n;

  std::vector<int> dp(n + 1, -1);
  dp[2] = dp[5] = 1;
  dp[4] = 2;

  for (int i = 6; i <= n; ++i) {
    if (dp[i - 2] != -1) dp[i] = dp[i - 2] + 1;
    if (dp[i - 5] != -1) dp[i] = std::min(dp[i], dp[i - 5] + 1);
  }

  std::cout << dp[n] << "\n";
}