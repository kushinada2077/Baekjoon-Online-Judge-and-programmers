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
  std::vector board(n, std::vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> board[i][j];
    }
  }

  std::vector vis(n, std::vector<bool>(m));
  std::vector<P> area;
  std::vector dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == '#' || vis[i][j]) continue;

      auto [o, v, ok] = [&] {
        int cnt_o = 0, cnt_v = 0;
        std::queue<P> q;
        q.push({i, j});
        vis[i][j] = true;

        while (!q.empty()) {
          auto [y, x] = q.front();
          q.pop();
          if (board[y][x] == 'o') cnt_o++;
          if (board[y][x] == 'v') cnt_v++;
          for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) return T(0, 0, 0);
            if (board[ny][nx] == '#' || vis[ny][nx]) continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
          }
        }

        return T(cnt_o, cnt_v, 1);
      }();

      if (ok) {
        area.push_back({o, v});
      }
    }
  }

  int ans_o = 0, ans_v = 0;
  for (auto [o, v] : area) {
    if (o > v) ans_o += o;
    else ans_v += v;
  }

  std::cout << ans_o << " " << ans_v << "\n";
}