#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
using F = std::tuple<int, int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector board(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> board[i][j];
    }
  }

  int ans = 0x3f3f3f3f;
  std::vector dy = {0, 1, 0, -1, 0}, dx = {0, 0, 1, 0, -1};
  std::vector<P> coor;
  auto dfs = [&](auto&& dfs, int k) {
    if ((int)coor.size() == 3) {
      std::set<P> s;
      int sum = 0;

      for (auto [y, x] : coor) {
        for (int dir = 0; dir < 5; ++dir) {
          int ny = y + dy[dir];
          int nx = x + dx[dir];
          if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
          s.insert({ny, nx});
          sum += board[ny][nx];
        }
      }

      if ((int)s.size() == 15) ans = std::min(ans, sum);
      return;
    }

    for (int i = k; i < n * n; ++i) {
      coor.push_back({i / n, i % n});
      dfs(dfs, i + 1);
      coor.pop_back();
    }
  };

  dfs(dfs, 0);
  std::cout << ans << "\n";
}