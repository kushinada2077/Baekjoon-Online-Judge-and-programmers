#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector str(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> str[i][j];
    }
  }

  std::vector vis(n, std::vector<bool>(m, false));
  std::vector<int> f_x[4] = {{0, -1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, 1}};
  std::vector<int> f_y[4] = {{0, 0, 1}, {0, 0, -1}, {0, -1, 0}, {0, 1, 0}};

  auto chk = [&](int y, int x, int form) {
    for (int dir = 0; dir < 3; ++dir) {
      int ny = y + f_y[form][dir];
      int nx = x + f_x[form][dir];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) return false;
      if (vis[ny][nx] == true) return false;
    }

    return true;
  };

  int ans = 0;
  auto dfs = [&](auto&& dfs, int y, int x, int tot) {
    if (y == n) {
      ans = std::max(ans, tot);
      return;
    }

    dfs(dfs, y + (x + 1) / m, (x + 1) % m, tot);
    for (int form = 0; form < 4; ++form) {
      if (chk(y, x, form) == false) continue;

      int sum = str[y][x];
      for (int dir = 0; dir < 3; ++dir) {
        int ny = y + f_y[form][dir];
        int nx = x + f_x[form][dir];
        sum += str[ny][nx];
        vis[ny][nx] = true;
      }

      dfs(dfs, y + (x + 1) / m, (x + 1) % m, tot + sum);

      for (int dir = 0; dir < 3; ++dir) {
        int ny = y + f_y[form][dir];
        int nx = x + f_x[form][dir];
        vis[ny][nx] = false;
      }
    }
  };

  dfs(dfs, 0, 0, 0);

  std::cout << ans << "\n";
}