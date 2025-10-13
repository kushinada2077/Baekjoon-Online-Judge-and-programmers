#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

struct DSU {
  std::vector<int> f, siz;

  DSU() {}
  DSU(int n) { init(n); }

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

  bool same(int x, int y) { return find(x) == find(y); }

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

  int size(int x) { return siz[find(x)]; }
};

void solve(int cnt) {
  int n, k;
  std::cin >> n >> k;
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < k; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  DSU dsu(n);
  for (int u = 0; u < n; ++u) {
    for (auto v : adj[u]) dsu.merge(u, v);
  }

  int m;
  std::cin >> m;
  std::cout << "Scenario " << cnt << ":\n";
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    if (dsu.same(u, v)) std::cout << 1 << "\n";
    else std::cout << 0 << "\n";
  }
  std::cout << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t, cnt = 1;
  std::cin >> t;
  while (t--) {
    solve(cnt++);
  }
}