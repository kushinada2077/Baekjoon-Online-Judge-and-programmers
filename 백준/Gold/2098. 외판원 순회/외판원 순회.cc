#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector dist(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> dist[i][j];
    }
  }

  const int INF = 0x3f3f3f3f;
  std::vector dp(n, std::vector<int>(1 << n, -1));

  auto dfs = [&](auto&& dfs, int u, int bit) {
    int& ret = dp[u][bit];
    if (ret != -1) return ret;
    if (bit == (1 << n) - 1) return dist[u][0] != 0 ? dist[u][0] : INF;
    ret = INF;
    for (int v = 0; v < n; ++v) {
      if (dist[u][v] == 0 || (bit & (1 << v)) > 0) continue;
      ret = std::min(ret, dfs(dfs, v, bit | (1 << v)) + dist[u][v]);
    }

    return ret;
  };

  std::cout << dfs(dfs, 0, 1) << "\n";
}