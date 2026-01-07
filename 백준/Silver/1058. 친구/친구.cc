#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector adj(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      std::cin >> c;
      adj[i][j] = (c == 'Y') ? 1 : 0;
    }
  }

  int ans = -1;
  for (int i = 0; i < n; ++i) {
    std::set<int> a;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (adj[i][j] == 1) {
        a.insert(j);
      } else {
        for (int k = 0; k < n; ++k) {
          if (adj[j][k] == 1 && adj[k][i] == 1) {
            a.insert(j);
          }
        }
      }
    }

    ans = std::max(ans, (int)a.size());
  }

  std::cout << ans << "\n";
}