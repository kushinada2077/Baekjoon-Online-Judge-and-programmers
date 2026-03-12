#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector b(n, std::vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> b[i][j];
    }
  }

  std::vector dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};
  std::vector<int> p(n * n, 1);
  p[0] = p[1] = p[2] = 0;

  do {
    std::vector<P> cs;
    for (int i = 0; i < n * n; ++i) {
      if (p[i] == 0) {
        cs.push_back({i / n, i % n});
      }
    }
    auto chk = [&] {
      for (auto [y, x] : cs) {
        if (b[y][x] == 'S' || b[y][x] == 'T') {
          return false;
        }
      }
      return true;
    }();
    if (!chk) {
      continue;
    }
    for (auto [y, x] : cs) {
      b[y][x] = 'O';
    }

    auto go = [&](int sy, int sx, int dir) {
      for (int step = 1;; ++step) {
        int ny = sy + dy[dir] * step;
        int nx = sx + dx[dir] * step;
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || b[ny][nx] == 'O') {
          break;
        }
        if (b[ny][nx] == 'S') {
          return false;
        }
      }
      return true;
    };

    bool ans = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (b[i][j] == 'T') {
          for (int dir = 0; dir < 4; ++dir) {
            ans &= go(i, j, dir);
          }
        }
      }
    }

    for (auto [y, x] : cs) {
      b[y][x] = 'X';
    }

    if (ans) {
      std::println("YES");
      return 0;
    }
  } while (std::next_permutation(p.begin(), p.end()));
  std::println("NO");
}