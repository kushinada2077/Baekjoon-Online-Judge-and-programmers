#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector path(n, std::vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    path[u][v] = 1;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (path[i][j] == 0 && path[i][k] == 1 && path[k][j] == 1) {
          path[i][j] = 1;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += [&]() {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (path[i][j] == 0 && path[j][i] == 0) return 0;
      }

      return 1;
    }();
  }

  std::cout << ans << "\n";
}