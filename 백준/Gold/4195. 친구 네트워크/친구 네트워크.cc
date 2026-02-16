#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

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
  kushinada;
  int tc;
  std::cin >> tc;

  while (tc--) {
    [&] {
      int f;
      std::cin >> f;
      std::unordered_map<std::string, int> S;
      auto StoI = [&](std::string& name) {
        if (S.contains(name)) return S[name];
        return S[name] = (int)S.size();
      };

      std::vector<std::pair<int, int>> query;
      for (int i = 0; i < f; ++i) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        int u = StoI(s1);
        int v = StoI(s2);
        query.emplace_back(u, v);
      }

      DSU dsu((int)S.size());

      for (auto [u, v] : query) {
        dsu.merge(u, v);
        std::cout << dsu.size(u) << "\n";
      }
    }();
  }
}