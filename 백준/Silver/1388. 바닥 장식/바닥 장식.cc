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
  std::vector board(n, std::vector<char>(m));
  std::vector vis(n, std::vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> board[i][j];
    }
  }

  std::vector<std::vector<int>> dy = {{0, 0}, {1, -1}}, dx = {{1, -1}, {0, 0}};

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vis[i][j]) continue;

      ans++;
      std::queue<P> q;
      q.push({i, j});
      vis[i][j] = true;
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        int idx = board[i][j] == '-' ? 0 : 1;
        for (int dir = 0; dir < 2; ++dir) {
          int ny = y + dy[idx][dir];
          int nx = x + dx[idx][dir];
          if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
          if (board[ny][nx] != board[y][x] || vis[ny][nx]) continue;
          q.push({ny, nx});
          vis[ny][nx] = true;
        }
      }
    }
  }

  std::cout << ans << "\n";
}