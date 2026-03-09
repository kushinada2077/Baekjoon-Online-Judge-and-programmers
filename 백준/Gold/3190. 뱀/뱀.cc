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
  int n, k;
  std::cin >> n >> k;
  std::vector b(n, std::vector<int>(n));
  for (int i = 0; i < k; ++i) {
    int y, x;
    std::cin >> y >> x;
    b[y - 1][x - 1] = -1;
  }
  int l;
  std::cin >> l;
  std::vector<char> dir_chg(10001, 'X');
  for (int i = 0; i < l; ++i) {
    int x;
    char c;
    std::cin >> x >> c;
    dir_chg[x - 1] = c;
  }

  std::vector dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};

  auto f = [&]() -> int {
    int s = 0;
    int dir = 1;
    int hy = 0, hx = 0;
    int ty = 0, tx = 0;
    int cnt = 2;
    b[0][0] = 1;
    for (; s < 10000; ++s) {
      int nhy = hy + dy[dir];
      int nhx = hx + dx[dir];
      if (nhy < 0 || nhy >= n || nhx < 0 || nhx >= n) return s;
      if (b[nhy][nhx] > 0) return s;
      if (b[nhy][nhx] == 0) {
        b[nhy][nhx] = cnt++;
        hy = nhy;
        hx = nhx;
        for (int dir = 0; dir < 4; ++dir) {
          int nty = ty + dy[dir];
          int ntx = tx + dx[dir];
          if (nty < 0 || nty >= n || ntx < 0 || ntx >= n) continue;
          if (b[ty][tx] + 1 == b[nty][ntx]) {
            b[ty][tx] = 0;
            ty = nty;
            tx = ntx;
            break;
          }
        }
      } else if (b[nhy][nhx] == -1) {
        b[nhy][nhx] = cnt++;
        hy = nhy;
        hx = nhx;
      }

      if (dir_chg[s] == 'L') {
        dir = (dir + 3) % 4;
      }
      if (dir_chg[s] == 'D') {
        dir = (dir + 1) % 4;
      }
    }

    return 0;
  };

  std::println("{}", f() + 1);
}