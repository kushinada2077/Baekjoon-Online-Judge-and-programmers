#include <bits/stdc++.h>
using i64 = long long;

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

  int n;
  std::cin >> n;
  DSU dsu(1000001);
  for (int i = 0; i < n; ++i) {
    char op;
    std::cin >> op;
    if (op == 'I') {
      int a, b;
      std::cin >> a >> b;
      dsu.merge(a, b);
    } else if (op == 'Q') {
      int c;
      std::cin >> c;
      std::cout << dsu.size(c) << "\n";
    }
  }
}