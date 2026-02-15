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
  std::vector board(n, std::vector<int>(n));
  std::vector dp(n, std::vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> board[i][j];
    }
  }

  std::vector dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};

  auto dfs = [&](auto&& dfs, int y, int x, int sum) -> int {
    int& res = dp[y][x];
    if (res != -1) return res;

    res = sum;
    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (board[ny][nx] <= board[y][x]) continue;
      res = std::max(res, sum + dfs(dfs, ny, nx, 1));
    }

    return res;
  };

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans = std::max(ans, dfs(dfs, i, j, 1));
    }
  }

  std::cout << ans << "\n";
}