#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<double> prob(4);
  for (int i = 0; i < 4; ++i) {
    int x;
    std::cin >> x;
    prob[i] = x / (double)100;
  }

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  double ans = 0;
  std::map<int, std::map<int, int>> vis;
  vis[0][0] = 1;
  auto dfs = [&](auto&& dfs, int y, int x, int c, double p) {
    if (c == n) {
      ans += p;
      return;
    }

    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if (vis[ny][nx] == 1) continue;
      vis[ny][nx] = 1;
      dfs(dfs, ny, nx, c + 1, p * prob[dir]);
      vis[ny][nx] = 0;
    }
  };

  dfs(dfs, 0, 0, 0, 1);
  std::cout << std::fixed << std::setprecision(20) << ans << "\n";
}