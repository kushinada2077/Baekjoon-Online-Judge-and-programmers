#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
const int INF = 1e9;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  i64 h, y;
  std::cin >> h >> y;

  i64 ans = 0;
  std::vector<P> c = {{5, 135}, {3, 120}, {1, 105}};

  auto dfs = [&](auto&& dfs, i64 h, i64 y) {
    if (y == 0) {
      ans = std::max(ans, h);
      return;
    }
    for (int i = 0; i < 3; ++i) {
      if (y >= c[i].first) {
        dfs(dfs, h * c[i].second / 100, y - c[i].first);
      }
    }

    return;
  };

  dfs(dfs, h, y);
  std::cout << ans << "\n";
}