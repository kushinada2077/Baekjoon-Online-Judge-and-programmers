#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_LPATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  i64 g;
  std::cin >> n >> m >> g;
  std::vector b(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> b[i][j];
    }
  }
  int cy, cx;
  std::cin >> cy >> cx;
  cy--;
  cx--;
  std::map<int, std::map<int, P>> cuss;
  std::map<int, std::map<int, int>> cost;
  std::vector dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};

  for (int i = 0; i < m; ++i) {
    int uy, ux, vy, vx;
    std::cin >> uy >> ux >> vy >> vx;
    uy--;
    ux--;
    vy--;
    vx--;
    cuss[uy][ux] = {vy, vx};

    std::vector dst(n, std::vector<int>(n, -1));
    std::queue<P> que;
    dst[uy][ux] = 0;
    que.push({uy, ux});
    while (!que.empty()) {
      auto [y, x] = que.front();
      que.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (b[ny][nx] == 0 && dst[ny][nx] == -1) {
          dst[ny][nx] = dst[y][x] + 1;
          que.push({ny, nx});
        }
      }
    }
    cost[uy][ux] = dst[vy][vx];
  }

  auto bfs = [&](int sy, int sx) -> std::vector<std::vector<int>> {
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
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (b[ny][nx] == 0 && dst[ny][nx] == -1) {
          dst[ny][nx] = dst[y][x] + 1;
          que.push({ny, nx});
        }
      }
    }

    return dst;
  };

  const int INF = 0x3f3f3f3f;
  bool ok = true;
  while (m--) {
    auto dst = bfs(cy, cx);
    int min_d = INF;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (cuss.contains(i) && cuss[i].contains(j) && dst[i][j] != -1) {
          min_d = std::min(min_d, dst[i][j]);
        }
      }
    }

    std::vector<P> x;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (cuss.contains(i) && cuss[i].contains(j) && dst[i][j] == min_d) {
          x.push_back({i, j});
        }
      }
    }

    std::ranges::sort(x);
    if (x.empty()) {
      ok = false;
      break;
    }

    auto [sy, sx] = x.front();
    auto [ty, tx] = cuss[sy][sx];
    int c = cost[sy][sx];
    if (c == -1) {
      ok = false;
      break;
    }
    cuss[sy].erase(sx);
    cost[sy].erase(sx);
    if (g < dst[sy][sx]) {
      ok = false;
      break;
    }
    g -= dst[sy][sx];
    if (g < c) {
      ok = false;
      break;
    }
    g += c;
    cy = ty;
    cx = tx;
  }

  if (ok) {
    std::println("{}", g);
  } else {
    std::println("{}", -1);
  }
}