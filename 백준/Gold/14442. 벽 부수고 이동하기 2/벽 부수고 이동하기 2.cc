#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

template <class T, class U>
inline bool chmin(T& a, const U& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::string> board(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> board[i];
  }

  std::queue<T> q;
  std::vector dist(n, std::vector<std::vector<int>>(m, std::vector<int>(k + 1, -1)));
  q.push({0, 0, k});
  dist[0][0][k] = 0;

  while (!q.empty()) {
    auto [y, x, d] = q.front();
    q.pop();

    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + "2101"[dir] - '1';
      int nx = x + "1210"[dir] - '1';
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (dist[ny][nx][d] != -1) continue;
      if (d > 0 && board[ny][nx] == '1' && dist[ny][nx][d - 1] == -1) {
        q.push({ny, nx, d - 1});
        dist[ny][nx][d - 1] = dist[y][x][d] + 1;
      } else if (board[ny][nx] == '0') {
        q.push({ny, nx, d});
        dist[ny][nx][d] = dist[y][x][d] + 1;
      }
    }
  }

  constexpr int IMP = 0x3f3f3f3f;
  int ans = IMP;
  for (int i = 0; i < k + 1; ++i) {
    if (dist[n - 1][m - 1][i] != -1) chmin(ans, dist[n - 1][m - 1][i]);
  }

  if (ans == IMP) ans = -2;
  std::cout << ans + 1 << "\n";
}