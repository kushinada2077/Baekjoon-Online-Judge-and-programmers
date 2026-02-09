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
  std::cin >> n >> m;
  std::vector<std::string> board(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> board[i];
  }

  std::queue<T> q;
  std::vector dist(2, std::vector(n, std::vector<int>(m, -1)));
  q.push(T(0, 0, 0));
  dist[0][0][0] = 0;
  std::vector dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};

  while (!q.empty()) {
    auto [used, y, x] = q.front();
    q.pop();

    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (board[ny][nx] == '1' && used == 1) continue;
      int n_used = used + (board[ny][nx] == '1');
      if (dist[n_used][ny][nx] != -1) continue;

      q.push(T(n_used, ny, nx));
      dist[n_used][ny][nx] = dist[used][y][x] + 1;
    }
  }

  int ans = dist[0][n - 1][m - 1];
  if (dist[1][n - 1][m - 1] != -1) ans = dist[1][n - 1][m - 1];
  if (ans != -1) ans++;
  std::cout << ans << "\n";
}