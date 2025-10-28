#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, h;
  std::cin >> m >> n >> h;
  std::vector box(n, std::vector(m, std::vector<int>(h, 0)));
  std::vector dist(n, std::vector(m, std::vector<int>(h, -1)));
  std::queue<T> q;
  for (int k = 0; k < h; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cin >> box[i][j][k];
        if (box[i][j][k] == 1) {
          q.push({i, j, k});
          dist[i][j][k] = 0;
        }
      }
    }
  }

  int ans = 0;
  std::vector dx = {1, 0, -1, 0, 0, 0}, dy = {0, 1, 0, -1, 0, 0}, dz = {0, 0, 0, 0, 1, -1};
  while (!q.empty()) {
    auto [y, x, z] = q.front();
    q.pop();
    for (int dir = 0; dir < 6; ++dir) {
      int ny = y + dy[dir], nx = x + dx[dir], nz = z + dz[dir];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || nz < 0 || nz >= h) continue;
      if (box[ny][nx][nz] != 0 || dist[ny][nx][nz] != -1) continue;
      q.push({ny, nx, nz});
      dist[ny][nx][nz] = dist[y][x][z] + 1;
      ans = std::max(ans, dist[ny][nx][nz]);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < h; ++k) {
        if (box[i][j][k] != -1 && dist[i][j][k] == -1) ans = -1;
      }
    }
  }

  std::cout << ans << "\n";
}