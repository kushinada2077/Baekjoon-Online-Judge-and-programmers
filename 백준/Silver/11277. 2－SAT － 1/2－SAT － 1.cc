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
  int n, m;
  std::cin >> n >> m;
  std::vector<bool> state(n);
  std::vector<P> clauses(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> clauses[i].first >> clauses[i].second;
  }

  auto dfs = [&](auto&& dfs, int k) {
    if (k == n) {
      for (auto [a, b] : clauses) {
        bool bool_a = state[std::abs(a) - 1];
        bool bool_b = state[std::abs(b) - 1];
        if (a < 0) bool_a = !bool_a;
        if (b < 0) bool_b = !bool_b;

        if (bool_a == false && bool_b == false) return 0;
      }

      return 1;
    }

    int ret = 0;
    ret = std::max(ret, dfs(dfs, k + 1));
    state[k] = true;
    ret = std::max(ret, dfs(dfs, k + 1));
    state[k] = false;

    return ret;
  };

  std::cout << dfs(dfs, 0) << "\n";
}