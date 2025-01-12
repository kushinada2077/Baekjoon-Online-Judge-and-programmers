#include <bits/stdc++.h>
using i64 = long long;

constexpr int M = 1e6 + 7;

i64 solve(int dx, int dy, std::vector<std::vector<i64>>& dp) {
  i64& ret = dp[dx][dy];
  if (ret != -1) return ret;
  if (dx == 0 || dy == 0) return ret = 1;
  else return ret = solve(dx - 1, dy, dp) + solve(dx, dy - 1, dp) % M;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int w, h, tx, ty;
  std::cin >> w >> h >> tx >> ty;
  std::vector dp(202, std::vector<i64>(202, -1));
  std::cout << solve(tx - 1, ty - 1, dp) * solve(w - tx, h - ty, dp) % M << "\n";
}