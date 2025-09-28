#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> board(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> board[i];
  }

  const int INF = 0x3f3f3f3f;
  std::vector dist(n, std::vector<int>(n, INF));
  std::deque<P> dq;
  dq.push_back({0, 0});
  dist[0][0] = 0;

  while (!dq.empty()) {
    auto [y, x] = dq.front();
    dq.pop_front();

    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + "2101"[dir] - '1';
      int nx = x + "1210"[dir] - '1';
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (board[ny][nx] == '1' && dist[ny][nx] > dist[y][x]) {
        dq.push_front({ny, nx});
        dist[ny][nx] = dist[y][x];
      }
      if (board[ny][nx] == '0' && dist[ny][nx] > dist[y][x] + 1) {
        dq.push_back({ny, nx});
        dist[ny][nx] = dist[y][x] + 1;
      }
    }
  }

  std::cout << dist[n - 1][n - 1] << "\n";
}