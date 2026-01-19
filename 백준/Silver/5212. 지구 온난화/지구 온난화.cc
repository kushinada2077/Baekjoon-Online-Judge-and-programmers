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
  int r, c;
  std::cin >> r >> c;
  std::vector board(r, std::vector<char>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cin >> board[i][j];
    }
  }

  std::vector dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};
  std::vector n_board(r, std::vector<char>(c, 'X'));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (board[i][j] == '.') {
        n_board[i][j] = '.';
        continue;
      }
      int cnt = 0;
      for (int dir = 0; dir < 4; ++dir) {
        int ni = i + dy[dir];
        int nj = j + dx[dir];
        if (ni < 0 || ni >= r || nj < 0 || nj >= c || board[ni][nj] == '.') cnt++;
      }

      if (cnt >= 3) n_board[i][j] = '.';
    }
  }

  int min_r = r, min_c = c, max_r = 0, max_c = 0;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (n_board[i][j] == 'X') {
        min_r = std::min(min_r, i);
        min_c = std::min(min_c, j);
        max_r = std::max(max_r, i);
        max_c = std::max(max_c, j);
      }
    }
  }

  for (int i = min_r; i <= max_r; ++i) {
    for (int j = min_c; j <= max_c; ++j) {
      std::cout << n_board[i][j];
      if (j == max_c) std::cout << "\n";
    }
  }
}