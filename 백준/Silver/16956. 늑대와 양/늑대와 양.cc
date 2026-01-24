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

  bool ok = true;
  std::vector dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};

  [&] {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (board[i][j] != 'W') continue;
        for (int dir = 0; dir < 4; ++dir) {
          int ny = i + dy[dir];
          int nx = j + dx[dir];
          if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
          if (board[ny][nx] == 'S') {
            ok = false;
            return;
          }
        }
      }
    }
  }();

  if (ok) {
    std::cout << "1\n";
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (board[i][j] == '.') std::cout << "D";
        else std::cout << board[i][j];
      }
      std::cout << "\n";
    }
  } else {
    std::cout << "0\n";
  }
}