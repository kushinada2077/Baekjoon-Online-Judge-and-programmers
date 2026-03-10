#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

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

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  std::cin >> n >> m;
  DSU dsu(n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      std::cin >> x;
      if (x) {
        dsu.merge(i, j);
      }
    }
  }

  int s;
  std::cin >> s;
  s--;
  for (int i = 0; i < m; ++i) {
    int x;
    std::cin >> x;
    x--;
    if (!dsu.same(s, x)) {
      std::println("NO");
      return 0;
    }
  }

  std::println("YES");
}