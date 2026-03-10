#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  std::cin >> n >> m;
  std::vector adj(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> adj[i][j];
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (adj[i][k] && adj[k][j]) adj[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    adj[i][i] = 1;
  }

  bool ans = [&] -> bool {
    int pre;
    std::cin >> pre;
    pre--;
    for (int i = 0; i < m - 1; ++i) {
      int x;
      std::cin >> x;
      x--;
      if (!adj[pre][x]) {
        return false;
      }
    }
    return true;
  }();

  if (ans) {
    std::println("YES");
  } else {
    std::println("NO");
  }
}