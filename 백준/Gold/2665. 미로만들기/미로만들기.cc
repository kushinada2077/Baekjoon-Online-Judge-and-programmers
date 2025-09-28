#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> board(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> board[i];
  }

  const int INF = 0x3f3f3f3f;
  std::vector cnt(n, std::vector<int>(n, INF));
  std::queue<P> q;
  q.push({0, 0});
  cnt[0][0] = 0;

  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + "2101"[dir] - '1';
      int nx = x + "1210"[dir] - '1';
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (board[ny][nx] == '0') {
        if (cnt[ny][nx] > cnt[y][x] + 1) {
          q.push({ny, nx});
          cnt[ny][nx] = cnt[y][x] + 1;
        }
      }
      if (board[ny][nx] == '1') {
        if (cnt[ny][nx] > cnt[y][x]) {
          q.push({ny, nx});
          cnt[ny][nx] = cnt[y][x];
        }
      }
    }
  }

  std::cout << cnt[n - 1][n - 1] << "\n";
}