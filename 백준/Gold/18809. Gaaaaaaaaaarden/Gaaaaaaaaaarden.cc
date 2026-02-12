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
  int n, m, g, r;
  std::cin >> n >> m >> g >> r;
  std::vector board(n, std::vector<int>(m));
  std::vector<P> candidate;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> board[i][j];
      if (board[i][j] == 2) candidate.push_back({i, j});
    }
  }

  int k = (int)candidate.size();
  std::vector<int> p(k, 0);
  int idx = k - 1;
  while (g--) {
    p[idx--] = 2;
  }
  while (r--) {
    p[idx--] = 1;
  }

  std::vector dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};
  int ans = 0;
  do {
    [&] {
      std::vector dist(n, std::vector(m, std::vector<int>(3, -1)));
      std::queue<T> q;
      int cnt = 0;
      for (int i = 0; i < k; ++i) {
        auto [y, x] = candidate[i];
        if (p[i] == 1) {
          q.push({y, x, 1});
          dist[y][x][1] = 0;
        }
        if (p[i] == 2) {
          q.push({y, x, 2});
          dist[y][x][2] = 0;
        }
      }

      while (!q.empty()) {
        auto [y, x, color] = q.front();
        q.pop();
        if (dist[y][x][color] == -2) continue;
        int diff_color = color == 1 ? 2 : 1;

        for (int dir = 0; dir < 4; ++dir) {
          int ny = y + dy[dir];
          int nx = x + dx[dir];
          if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
          if (board[ny][nx] == 0 || dist[ny][nx][color] != -1) continue;
          if (dist[ny][nx][diff_color] != -1 && dist[ny][nx][diff_color] != dist[y][x][color] + 1) continue;
          if (dist[ny][nx][diff_color] != -1 && dist[ny][nx][diff_color] == dist[y][x][color] + 1) {
            cnt++;
            dist[ny][nx][diff_color] = dist[ny][nx][color] = -2;
            continue;
          }
          q.push({ny, nx, color});
          dist[ny][nx][color] = dist[y][x][color] + 1;
        }
      }

      ans = std::max(ans, cnt);
    }();
  } while (std::next_permutation(p.begin(), p.end()));

  std::cout << ans << "\n";
}