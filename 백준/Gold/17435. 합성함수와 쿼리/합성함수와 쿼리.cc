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
  int m;
  std::cin >> m;
  int b = 0;
  while ((1 << b) <= 500000) b++;
  std::vector f(b, std::vector<int>(m, -1));
  for (int i = 0; i < m; ++i) {
    std::cin >> f[0][i];
    f[0][i]--;
  }

  for (int k = 1; k < b; ++k) {
    for (int i = 0; i < m; ++i) {
      f[k][i] = f[k - 1][f[k - 1][i]];
    }
  }

  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int n, x;
    std::cin >> n >> x;
    x--;
    for (int cur = 0; n; n /= 2, cur++) {
      if (n % 2 == 0) continue;
      x = f[cur][x];
    }

    std::cout << x + 1 << "\n";
  }
}