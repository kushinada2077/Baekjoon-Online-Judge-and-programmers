#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using TP = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  const int IMP = 0x3f3f3f3f;
  std::vector dp(n, std::vector<int>(2, IMP));

  auto dfs = [&](auto&& dfs, int u, int opt, int p) {
    int& ret = dp[u][opt];
    if (ret != IMP) {
      return ret;
    }

    ret = opt ? 1 : 0;

    for (auto v : adj[u]) {
      if (p != v) {
        if (!opt) {
          ret += dfs(dfs, v, 1, u);
        } else {
          ret += std::min(dfs(dfs, v, 0, u), dfs(dfs, v, 1, u));
        }
      }
    }
    return ret;
  };

  std::println("{}", std::min(dfs(dfs, 0, 1, -1), dfs(dfs, 0, 0, -1)));
}