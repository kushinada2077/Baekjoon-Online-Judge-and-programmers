#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using P_i64 = std::pair<i64, i64>;

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

  std::vector<int> ans2;
  std::vector dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};
  int ans1 = 0;

  while (true) {
    std::queue<P> pre_q, q;
    std::vector dist(n, std::vector<int>(m, -1));
    pre_q.push({0, 0});
    dist[0][0] = 0;
    while (!pre_q.empty()) {
      auto [y, x] = pre_q.front();
      pre_q.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (dist[ny][nx] != -1) continue;
        if (board[ny][nx] == 1) {
          q.push({ny, nx});
          dist[ny][nx] = 0;
        } else {
          pre_q.push({ny, nx});
          dist[ny][nx] = dist[y][x] + 1;
        }
      }
    }

    if (!q.empty()) {
      ans1++;
      ans2.push_back((int)q.size());
    } else {
      break;
    }
    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();
      board[y][x] = 0;
    }
  }

  std::cout << ans1 << "\n" << ans2.back() << "\n";
}