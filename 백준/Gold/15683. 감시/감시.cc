#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector b(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> b[i][j];
    }
  }

  int ans = 0x3f3f3f3f;
  int bf = 1 << 16;
  std::vector<std::vector<int>> w = {{0}, {0, 2}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3}};
  for (int i = 0; i < bf; ++i) {
    int j = i;
    std::vector c(n, std::vector<bool>(m));
    auto fill = [&](int y, int x, int t, int d) {
      for (auto dw : w[t - 1]) {
        for (int yy = y, xx = x; yy >= 0 && yy < n && xx >= 0 && xx < m && b[yy][xx] != 6;) {
          c[yy][xx] = true;
          yy += "2101"[(d + dw) % 4] - '1';
          xx += "1210"[(d + dw) % 4] - '1';
        }
      }
    };
    for (int p = 0; p < n; ++p) {
      for (int q = 0; q < m; ++q) {
        if (b[p][q] > 0 && b[p][q] < 6) {
          fill(p, q, b[p][q], j % 4);
          j /= 4;
        }
      }
    }

    int cnt = 0;
    for (int p = 0; p < n; ++p) {
      for (int q = 0; q < m; ++q) {
        cnt += (c[p][q] == false && b[p][q] == 0);
      }
    }

    ans = std::min(ans, cnt);
  }

  std::cout << ans << "\n";
}