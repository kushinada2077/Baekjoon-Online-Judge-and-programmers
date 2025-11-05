#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> ans(n + 1, 0);
  std::vector adj(n + 1, std::vector<int>());
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x == -1) continue;
    adj[x].push_back(i + 1);
  }

  for (int i = 0; i < m; ++i) {
    int u, w;
    std::cin >> u >> w;
    ans[u] += w;
  }

  std::vector<bool> vis(n + 1, false);
  auto dfs = [&](auto&& dfs, int u) {
    if (vis[u] == true) return;
    vis[u] = true;
    for (auto v : adj[u]) {
      ans[v] += ans[u];
      dfs(dfs, v);
    }
  };

  dfs(dfs, 1);

  for (int i = 0; i < n; ++i) std::cout << ans[i + 1] << " ";
}