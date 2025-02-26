#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector a(n, std::vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }

  auto max_seq = [&]() {
    int ret = 1;
    for (int i = 0; i < n; ++i) {
      int cnt = 1;
      for (int j = 1; j < n; ++j) {
        if (a[i][j] != a[i][j - 1]) {
          cnt = 1;
        } else {
          cnt++;
        }
        ret = std::max(ret, cnt);
      }
    }

    for (int j = 0; j < n; ++j) {
      int cnt = 1;
      for (int i = 1; i < n; ++i) {
        if (a[i][j] != a[i - 1][j]) {
          cnt = 1;
        } else {
          cnt++;
        }
        ret = std::max(ret, cnt);
      }
    }

    return ret;
  };

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int dir = 0; dir < 2; ++dir) {
        int ni = i + "21"[dir] - '1';
        int nj = j + "12"[dir] - '1';
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) {
          continue;
        }
        if (a[i][j] == a[ni][nj]) {
          continue;
        }
        std::swap(a[i][j], a[ni][nj]);
        ans = std::max(ans, max_seq());
        std::swap(a[i][j], a[ni][nj]);
      }
    }
  }

  std::cout << ans << "\n";
}