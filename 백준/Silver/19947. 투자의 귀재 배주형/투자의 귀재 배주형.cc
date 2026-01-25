#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
const int INF = 1e9;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  i64 h, y;
  std::cin >> h >> y;
  std::vector<i64> dp(y + 1);

  dp[y] = h;

  for (int i = y - 1; i >= 0; --i) {
    if (i + 5 <= y) dp[i] = std::max(dp[i], dp[i + 5] * 135 / 100);
    if (i + 3 <= y) dp[i] = std::max(dp[i], dp[i + 3] * 120 / 100);
    if (i + 1 <= y) dp[i] = std::max(dp[i], dp[i + 1] * 105 / 100);
  }

  std::cout << dp[0] << "\n";
}