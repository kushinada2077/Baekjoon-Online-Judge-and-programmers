#include <bits/stdc++.h>
using i64 = long long;

constexpr int INF = 0x3f3f3f3f;
bool solve(int k) {
  int n;
  std::cin >> n;
  if (n == 0) return false;

  std::vector a(n, std::vector<int>(3)), dp(n, std::vector<int>(3, INF));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cin >> a[i][j];
    }
  }
  dp[n - 1][1] = a[n - 1][1];
  for (int y = n - 1; y >= 0; --y) {
    for (int x = 2; x >= 0; --x) {
      for (int dir = 0; dir < 4; ++dir) {
        int ny = y + "0100"[dir] - '1';
        int nx = x + "1002"[dir] - '1';
        if (ny < 0 || nx < 0 || ny >= n || nx >= 3) continue;
        dp[ny][nx] = std::min(dp[ny][nx], dp[y][x] + a[ny][nx]);
      }
    }
  }
  std::cout << k << ". " << dp[0][1] << "\n";
  return true;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int k = 1;
  while (solve(k)) {
    k++;
  }
}