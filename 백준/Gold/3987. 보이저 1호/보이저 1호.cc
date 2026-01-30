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

  int pr, pc;
  std::cin >> pr >> pc;
  pr--;
  pc--;

  std::map<char, std::map<int, int>> reflection;
  reflection['\\'][0] = 3;
  reflection['\\'][3] = 0;
  reflection['\\'][1] = 2;
  reflection['\\'][2] = 1;

  reflection['/'][3] = 2;
  reflection['/'][1] = 0;
  reflection['/'][2] = 3;
  reflection['/'][0] = 1;

  std::vector dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};

  int ans = 0, ans_dir = -1;
  std::vector dir_to_c = {'U', 'R', 'D', 'L'};
  for (int dir = 0; dir < 4; ++dir) {
    std::vector vis(n, std::vector(m, std::vector<bool>(4)));
    auto move = [&](auto&& move, int y, int x, int dir, int time) {
      if (y < 0 || y >= n || x < 0 || x >= m) return time;
      if (board[y][x] == 'C') return time;
      if (vis[y][x][dir]) return 0x3f3f3f3f;

      int ret;

      if (board[y][x] == '/' || board[y][x] == '\\') {
        int nxt_dir = reflection[board[y][x]][dir];
        vis[y][x][dir] = true;
        ret = move(move, y + dy[nxt_dir], x + dx[nxt_dir], nxt_dir, time + 1);
      } else {
        ret = move(move, y + dy[dir], x + dx[dir], dir, time + 1);
      }

      return ret;
    };

    int result = move(move, pr, pc, dir, 0);

    if (ans < result) {
      ans = result;
      ans_dir = dir;
    }
  }

  std::cout << dir_to_c[ans_dir] << "\n";
  if (ans == 0x3f3f3f3f) std::cout << "Voyager\n";
  else std::cout << ans << "\n";
}