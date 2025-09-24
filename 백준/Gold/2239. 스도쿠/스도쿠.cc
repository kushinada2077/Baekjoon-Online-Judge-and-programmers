#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<std::string> board(9);
  std::vector r(9, std::vector<int>(10, 0)), c(9, std::vector<int>(10, 0)), s(9, std::vector<int>(10, 0));
  for (int i = 0; i < 9; ++i) {
    std::cin >> board[i];
    for (int j = 0; j < 9; ++j) {
      if (board[i][j] != '0') {
        r[i][board[i][j] - '0'] = 1;
        c[j][board[i][j] - '0'] = 1;
        s[i / 3 * 3 + j / 3][board[i][j] - '0'] = 1;
      }
    }
  }

  auto solve = [&](auto&& solve, int y, int x) -> void {
    if (y == 9) {
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          std::cout << board[i][j];
        }
        std::cout << "\n";
      }

      exit(0);
    }

    if (board[y][x] != '0') {
      solve(solve, y + (x + 1) / 9, (x + 1) % 9);
      return;
    }

    for (int i = 1; i <= 9; ++i) {
      if (r[y][i] == 0 && c[x][i] == 0 && s[y / 3 * 3 + x / 3][i] == 0) {
        char tmp = board[y][x];
        board[y][x] = (char)(i + '0');
        r[y][i] = c[x][i] = s[y / 3 * 3 + x / 3][i] = 1;
        solve(solve, y + (x + 1) / 9, (x + 1) % 9);
        board[y][x] = tmp;
        r[y][i] = c[x][i] = s[y / 3 * 3 + x / 3][i] = 0;
      }
    }
  };

  solve(solve, 0, 0);
}