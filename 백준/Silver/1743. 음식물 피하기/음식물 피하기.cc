#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector a(n, std::vector<int>(m));
  std::vector vis(n, std::vector<bool>(m));

  for (int i = 0; i < k; ++i) {
    int y, x;
    std::cin >> y >> x;
    a[y - 1][x - 1] = 1;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 0 || vis[i][j] == true) {
        continue;
      }

      std::queue<std::pair<int, int>> q;
      q.push({i, j});
      vis[i][j] = true;
      int cnt = 0;
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        cnt++;
        for (int dir = 0; dir < 4; ++dir) {
          int ny = y + "2101"[dir] - '1';
          int nx = x + "1210"[dir] - '1';
          if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            continue;
          }
          if (vis[ny][nx] == true || a[ny][nx] == 0) {
            continue;
          }
          q.push({ny, nx});
          vis[ny][nx] = true;
        }
      }

      ans = std::max(ans, cnt);
    }
  }

  std::cout << ans << "\n";
}