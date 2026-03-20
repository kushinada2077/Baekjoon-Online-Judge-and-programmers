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
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  adj.push_back({0});
  std::queue<int> que;
  que.push(n);
  std::vector<int> p(n + 1, -1);
  std::vector dp(n + 1, std::vector<int>(2, -1));

  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto v : adj[u]) {
      if (p[v] == -1) {
        p[v] = u;
        que.push(v);
      }
    }
  }

  auto dfs = [&](auto&& dfs, int u, int opt) {
    int& ret = dp[u][opt];
    if (ret != -1) {
      return ret;
    }
    ret = opt ? a[u] : 0;
    for (auto v : adj[u]) {
      if (p[u] != v) {
        if (opt) {
          ret += dfs(dfs, v, 0);
        } else {
          ret += std::max(dfs(dfs, v, 0), dfs(dfs, v, 1));
        }
      }
    }
    return ret;
  };

  std::println("{}", dfs(dfs, n, 0));
}