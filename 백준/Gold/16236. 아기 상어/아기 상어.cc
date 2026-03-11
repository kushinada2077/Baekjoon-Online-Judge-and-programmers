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
  std::vector b(n, std::vector<int>(n));
  int cy = -1, cx = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> b[i][j];
      if (b[i][j] == 9) {
        cy = i;
        cx = j;
      }
    }
  }

  int sz = 2, ans = 0, cnt = 0;
  std::vector dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};
  auto bfs = [&](int sy, int sx) -> P {
    std::vector dst(n, std::vector<int>(n, -1));
    std::queue<P> que;
    dst[sy][sx] = 0;
    que.push({sy, sx});
    while (!que.empty()) {
      auto [y, x] = que.front();
      que.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
          continue;
        }
        if (dst[ny][nx] == -1 && b[ny][nx] <= sz) {
          dst[ny][nx] = dst[y][x] + 1;
          que.push({ny, nx});
        }
      }
    }

    int min_d = 0x3f3f3f3f;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dst[i][j] != -1 && 1 <= b[i][j] && b[i][j] <= 6 && sz > b[i][j]) {
          min_d = std::min(min_d, dst[i][j]);
        }
      }
    }

    std::vector<P> fs;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dst[i][j] == min_d && 1 <= b[i][j] && b[i][j] <= 6 && sz > b[i][j]) {
          fs.push_back({i, j});
        }
      }
    }

    if (fs.empty()) {
      return {-1, -1};
    }
    std::ranges::sort(fs);
    auto [ty, tx] = fs.front();
    ans += min_d;
    return {ty, tx};
  };

  while (true) {
    auto [ny, nx] = bfs(cy, cx);
    if (ny == -1 && nx == -1) {
      break;
    }
    cnt++;
    if (sz == cnt) {
      cnt = 0;
      sz++;
    }
    b[ny][nx] = 9;
    b[cy][cx] = 0;
    cy = ny;
    cx = nx;
  }

  std::println("{}", ans);
}