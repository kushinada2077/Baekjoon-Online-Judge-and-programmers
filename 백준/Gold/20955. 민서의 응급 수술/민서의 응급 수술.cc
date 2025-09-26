#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<std::vector<int>> component;
  std::vector<bool> vis(n);
  auto dfs = [&](auto&& dfs, int u) {
    if (vis[u] == true) return;
    component.back().push_back(u);
    vis[u] = true;
    for (auto v : adj[u]) dfs(dfs, v);
  };

  for (int i = 0; i < n; ++i) {
    if (vis[i] == false) {
      component.push_back({});
      dfs(dfs, i);
    }
  }

  i64 ans = (int)component.size() - 1;
  for (int i = 0; i < (int)component.size(); ++i) {
    int v = (int)component[i].size(), e = 0;
    for (auto u : component[i]) {
      e += (int)adj[u].size();
    }

    e /= 2;

    ans += std::abs((v - 1) - e);
  }

  std::cout << ans << "\n";
}