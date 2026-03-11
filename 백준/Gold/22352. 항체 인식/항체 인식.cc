#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  std::cin >> n >> m;
  std::vector a(n, std::vector<int>(m)), b(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> b[i][j];
    }
  }

  std::vector dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};

  [&] {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] != b[i][j]) {
          int ori = a[i][j];
          std::queue<P> que;
          std::vector vis(n, std::vector<int>(m));
          vis[i][j] = 1;
          que.push({i, j});
          while (!que.empty()) {
            auto [y, x] = que.front();
            que.pop();
            a[y][x] = b[i][j];
            for (int dir = 0; dir < 4; ++dir) {
              int ny = y + dy[dir];
              int nx = x + dx[dir];
              if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
              if (ori != a[ny][nx] || vis[ny][nx]) continue;
              vis[ny][nx] = 1;
              que.push({ny, nx});
            }
          }
          return;
        }
      }
    }
  }();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) {
        std::println("NO");
        return 0;
      }
    }
  }
  std::println("YES");
}