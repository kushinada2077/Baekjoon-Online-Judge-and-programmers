#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, d;
  std::cin >> n >> m >> d;
  std::vector board(n, std::vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> board[i][j];
    }
  }

  std::vector<int> arc(m, 1);
  std::fill(arc.begin(), arc.begin() + 3, 0);
  int ans = 0;

  std::vector<int> dy = {0, -1, 0}, dx = {-1, 0, 1};

  do {
    int cnt = 0;
    std::vector n_board = board;

    while (true) {
      std::set<P> coor;
      for (int j = 0; j < m; ++j) {
        if (arc[j] == 1) continue;
        std::queue<P> q;
        std::vector dist(n + 1, std::vector<int>(m, -1));
        q.push({n, j});
        dist[n][j] = 0;
        bool end = false;

        while (!q.empty()) {
          auto [y, x] = q.front();
          q.pop();
          if (dist[y][x] >= d) continue;

          for (int dir = 0; dir < 3; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (dist[ny][nx] != -1) continue;
            if (n_board[ny][nx] == 1) {
              coor.insert({ny, nx});
              end = true;
              break;
            }

            q.push({ny, nx});
            dist[ny][nx] = dist[y][x] + 1;
          }
          if (end == true) break;
        }
      }

      cnt += (int)coor.size();
      for (auto [y, x] : coor) {
        n_board[y][x] = 0;
      }

      for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
          if (n_board[i][j] == 1) {
            n_board[i][j] = 0;
            if (i + 1 < n) n_board[i + 1][j] = 1;
          }
        }
      }

      bool chk = false;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          chk |= (n_board[i][j] == 1);
        }
      }

      if (chk == false) break;
    }

    ans = std::max(ans, cnt);
  } while (std::next_permutation(arc.begin(), arc.end()));

  std::cout << ans << "\n";
}