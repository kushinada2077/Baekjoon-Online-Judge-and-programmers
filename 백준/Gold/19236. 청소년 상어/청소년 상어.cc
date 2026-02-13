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

  std::vector board(4, std::vector<P>(4));
  std::vector<P> fishes(16);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cin >> board[i][j].first >> board[i][j].second;
      board[i][j].first--;
      board[i][j].second--;
      fishes[board[i][j].first] = P(i, j);
    }
  }

  std::vector dy = {-1, -1, 0, 1, 1, 1, 0, -1}, dx = {0, -1, -1, -1, 0, 1, 1, 1};
  int ans = board[0][0].first + 1;

  auto dfs = [&](auto&& dfs, int y, int x, int dir, int sum, std::vector<std::vector<P>> board, std::vector<P> fishes) -> void {
    for (int i = 0; i < 16; ++i) {
      if (fishes[i] == P(-1, -1)) continue;
      auto [y, x] = fishes[i];
      int st_dir = board[y][x].second;

      for (int dir = st_dir, cnt = 0; cnt < 8; dir = (dir + 1) % 8, cnt++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
        if (board[ny][nx] == P(-2, -2)) continue;
        if (board[ny][nx] != P(-1, -1)) std::swap(fishes[i], fishes[board[ny][nx].first]);
        else fishes[i] = P(ny, nx);
        std::swap(board[y][x], board[ny][nx]);
        board[ny][nx].second = dir;
        break;
      }
    }

    for (int ny = y + dy[dir], nx = x + dx[dir]; 0 <= ny && ny < 4 && 0 <= nx && nx < 4; ny += dy[dir], nx += dx[dir]) {
      if (board[ny][nx] == P(-1, -1)) continue;
      auto [num, new_dir] = board[ny][nx];
      auto new_board = board;
      auto new_fishes = fishes;
      new_fishes[num] = P(-1, -1);
      new_board[y][x] = P(-1, -1);
      new_board[ny][nx] = P(-2, -2);
      dfs(dfs, ny, nx, new_dir, sum + num + 1, new_board, new_fishes);
    }

    ans = std::max(ans, sum);
  };

  int dir = board[0][0].second;
  fishes[board[0][0].first] = P(-1, -1);
  board[0][0] = P(-2, -2);
  dfs(dfs, 0, 0, dir, ans, board, fishes);
  std::cout << ans << "\n";
}