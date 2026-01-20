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
  int n, m;
  std::cin >> n >> m;
  std::vector board(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> board[i][j];
    }
  }

  std::vector dy = {-1, -1, -1, 0, 1, 1, 1, 0}, dx = {-1, 0, 1, 1, 1, 0, -1, -1};
  std::queue<P> q;
  std::vector vis(n, std::vector<bool>(m));
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 1 && !vis[i][j]) {
        ans++;
        q.push({i, j});
        vis[i][j] = true;

        while (!q.empty()) {
          auto [y, x] = q.front();
          q.pop();
          for (int dir = 0; dir < 8; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (board[ny][nx] == 0 || vis[ny][nx]) continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
          }
        }
      }
    }
  }

  std::cout << ans << "\n";
}