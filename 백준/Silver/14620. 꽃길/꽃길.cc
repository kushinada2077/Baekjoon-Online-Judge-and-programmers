#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
using F = std::tuple<int, int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector board(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> board[i][j];
    }
  }

  int ans = 0x3f3f3f3f;
  std::vector dy = {0, 1, 0, -1, 0}, dx = {0, 0, 1, 0, -1};
  std::vector<P> coor;
  std::vector vis(n, std::vector<bool>(n));
  auto dfs = [&](auto&& dfs, int k) {
    if ((int)coor.size() == 3) {
      int sum = 0;

      for (auto [y, x] : coor) {
        sum += board[y][x] + board[y + 1][x] + board[y - 1][x] + board[y][x + 1] + board[y][x - 1];
      }

      ans = std::min(ans, sum);
      return;
    }

    for (int i = k; i < n * n; ++i) {
      int y = i / n, x = i % n;
      if (y == 0 || y == n - 1 || x == 0 || x == n - 1) continue;
      if (vis[y][x] || vis[y + 1][x] || vis[y - 1][x] || vis[y][x + 1] || vis[y][x - 1]) continue;
      coor.push_back({y, x});
      vis[y][x] = vis[y + 1][x] = vis[y - 1][x] = vis[y][x + 1] = vis[y][x - 1] = true;
      dfs(dfs, i + 1);
      coor.pop_back();
      vis[y][x] = vis[y + 1][x] = vis[y - 1][x] = vis[y][x + 1] = vis[y][x - 1] = false;
    }
  };

  dfs(dfs, 0);
  std::cout << ans << "\n";
}