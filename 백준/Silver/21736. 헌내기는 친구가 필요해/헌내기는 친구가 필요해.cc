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
  std::queue<P> q;
  std::vector vis(n, std::vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> board[i][j];

      if (board[i][j] == 'I') {
        q.push({i, j});
        vis[i][j] = true;
      }
    }
  }

  std::vector dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (board[ny][nx] == 'X' || vis[ny][nx]) continue;
      q.push({ny, nx});
      vis[ny][nx] = true;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'P' && vis[i][j] == true) cnt++;
    }
  }

  if (cnt == 0) {
    std::cout << "TT\n";
  } else {
    std::cout << cnt << "\n";
  }
}