#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

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

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  i64 ans = 0;
  std::cin >> n >> m;
  std::vector<T> edge(m);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    u--;
    v--;
    edge[i] = {c, u, v};
    ans += c;
  }

  std::ranges::sort(edge);
  DSU dsu(n);
  int cur_m = 0;
  i64 tot = 0;

  for (int i = 0; i < m && cur_m < n - 1; ++i) {
    auto [c, u, v] = edge[i];
    if (dsu.same(u, v)) continue;
    dsu.merge(u, v);
    cur_m++;
    tot += c;
  }

  if (dsu.size(0) != n) std::cout << "-1\n";
  else std::cout << ans - tot << "\n";
}