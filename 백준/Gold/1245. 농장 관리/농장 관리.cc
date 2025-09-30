#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

template <class T, class U>
inline bool chmax(T& a, const U& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector board(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> board[i][j];
    }
  }

  std::vector<int> dy = {-1, -1, -1, 0, 1, 1, 1, 0};
  std::vector<int> dx = {-1, 0, 1, 1, 1, 0, -1, -1};
  auto bfs = [&](int sy, int sx, std::vector<std::vector<int>>& vis) {
    std::vector<P> ret;
    std::queue<P> q;
    q.push({sy, sx});
    vis[sy][sx] = 1;

    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();
      ret.push_back({y, x});
      for (int dir = 0; dir < 8; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (vis[ny][nx] == 1 || board[ny][nx] != board[sy][sx]) continue;
        q.push({ny, nx});
        vis[ny][nx] = 1;
      }
    }

    return ret;
  };

  auto cnt = [&](int sy, int sx, std::vector<std::vector<int>>& vis) {
    auto coor = bfs(sy, sx, vis);
    for (auto [y, x] : coor) {
      for (int dir = 0; dir < 8; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (board[ny][nx] > board[sy][sx]) return 0;
      }
    }

    return 1;
  };

  int ans = 0;
  std::vector vis(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vis[i][j] == 0) {
        int d = cnt(i, j, vis);
        ans += d;
      }
    }
  }
  std::cout << ans << "\n";
}