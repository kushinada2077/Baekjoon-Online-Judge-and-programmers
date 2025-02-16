#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector a(n, std::vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }

  int ans = 0;
  int dy[6] = {-1, -1, 0, 0, 1, 1};
  int dx[2][6] = {{0, -1, -1, 1, 0, -1}, {0, 1, -1, 1, 0, 1}};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '.') continue;
      for (int dir = 0; dir < 6; ++dir) {
        int ny = i + dy[dir];
        int nx = j + dx[i % 2][dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        ans += a[ny][nx] == '.';
      }
    }
  }

  std::cout << ans << "\n";
}