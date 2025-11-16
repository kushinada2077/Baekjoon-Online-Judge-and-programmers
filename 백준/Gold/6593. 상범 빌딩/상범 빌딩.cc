#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

bool solve() {
  int h, n, m;
  std::string _;
  std::cin >> h >> n >> m;
  if (h == 0 && n == 0 && m == 0) return false;
  std::vector board(h, std::vector<std::string>(n));
  T st, dest;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> board[i][j];
      for (int k = 0; k < m; ++k) {
        if (board[i][j][k] == 'S') st = std::make_tuple(i, j, k);
        if (board[i][j][k] == 'E') dest = std::make_tuple(i, j, k);
      }
    }
  }

  std::vector dz = {0, 0, 0, 0, 1, -1}, dy = {1, 0, -1, 0, 0, 0}, dx = {0, 1, 0, -1, 0, 0};
  std::queue<T> q;
  std::vector dist(h, std::vector(n, std::vector<int>(m, -1)));
  q.push(st);
  auto [sz, sy, sx] = st;
  dist[sz][sy][sx] = 0;
  while (!q.empty()) {
    auto [z, y, x] = q.front();
    q.pop();

    for (int dir = 0; dir < 6; ++dir) {
      int nz = z + dz[dir], ny = y + dy[dir], nx = x + dx[dir];
      if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (board[nz][ny][nx] == '#' || dist[nz][ny][nx] != -1) continue;
      q.push(T(nz, ny, nx));
      dist[nz][ny][nx] = dist[z][y][x] + 1;
    }
  }

  auto [z, y, x] = dest;
  if (dist[z][y][x] == -1) std::cout << "Trapped!\n";
  else std::cout << "Escaped in " << dist[z][y][x] << " minute(s).\n";
  return true;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  while (solve());
}