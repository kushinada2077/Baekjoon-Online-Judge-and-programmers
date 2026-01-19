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
  int n, m;
  std::cin >> m >> n;
  std::vector board(n, std::vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> board[i][j];
    }
  }

  std::vector vis(n, std::vector<bool>(m, false));
  vis[0][0] = true;
  std::vector dy = {1, 0}, dx = {0, 1};

  auto dfs = [&](auto&& dfs, int y, int x) {
    if (y == n - 1 && x == m - 1) return true;

    bool ret = false;
    for (int dir = 0; dir < 2; ++dir) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (board[ny][nx] == 0 || vis[ny][nx] == true) continue;
      vis[ny][nx] = true;
      ret |= dfs(dfs, ny, nx);
    }

    return ret;
  };

  vis[0][0] = true;
  if (dfs(dfs, 0, 0)) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}