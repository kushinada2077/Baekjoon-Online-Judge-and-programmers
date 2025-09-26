#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

struct DSU {
  std::vector<int> f, siz;

  DSU() {}
  DSU(int n) {
    init(n);
  }

  void init(int n) {
    f.resize(n);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) {
      std::swap(x, y);
    }
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }

  int size(int x) {
    return siz[find(x)];
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector adj(n, std::vector<int>());
  std::vector<P> edge(m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edge[i] = {u, v};
  }

  int component = 0;
  std::vector<bool> vis(n);
  auto dfs = [&](auto&& dfs, int u) {
    if (vis[u] == true) return;
    vis[u] = true;
    for (auto v : adj[u]) dfs(dfs, v);
  };

  for (int i = 0; i < n; ++i) {
    if (vis[i] == false) {
      component++;
      dfs(dfs, i);
    }
  }

  int ans = component - 1;
  DSU dsu(n);

  for (auto [u, v] : edge) {
    if (dsu.same(u, v)) ans++;
    else dsu.merge(u, v);
  }

  std::cout << ans << "\n";
}