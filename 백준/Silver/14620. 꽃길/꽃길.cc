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
  std::vector<int> comb(n * n, 1);
  std::fill(comb.begin(), comb.begin() + 3, 0);
  int ans = 0x3f3f3f3f;

  std::vector dy = {0, 1, 0, -1, 0}, dx = {0, 0, 1, 0, -1};
  do {
    std::vector vis(n, std::vector<bool>(n));
    std::vector<P> coor;
    for (int i = 0; i < n * n; ++i) {
      if (comb[i] == 0) coor.push_back({i / n, i % n});
    }

    for (auto [y, x] : coor) {
      for (int dir = 0; dir < 5; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        vis[ny][nx] = true;
      }
    }

    int cnt = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (vis[i][j] == true) {
          cnt++;
          sum += board[i][j];
        }
      }
    }

    if (cnt == 15) ans = std::min(ans, sum);
  } while (std::next_permutation(comb.begin(), comb.end()));

  std::cout << ans << "\n";
}