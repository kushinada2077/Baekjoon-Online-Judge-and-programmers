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
  int n;
  std::cin >> n;
  int r1, c1, r2, c2;
  std::cin >> r1 >> c1 >> r2 >> c2;
  std::queue<P> q;
  std::vector dist(n, std::vector<int>(n, -1));
  q.push({r1, c1});
  dist[r1][c1] = 0;

  std::vector dy = {-2, -2, 0, 0, 2, 2}, dx = {-1, 1, -2, 2, -1, 1};
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int dir = 0; dir < 6; ++dir) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (dist[ny][nx] != -1) continue;
      q.push({ny, nx});
      dist[ny][nx] = dist[y][x] + 1;
    }
  }

  std::cout << dist[r2][c2] << "\n";
}