#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;
using F = std::tuple<int, int, int, int>;

struct SCC {
  int n;
  int cur, cnt;
  std::vector<std::vector<int>> adj;
  std::vector<int> dfn, low, bel;
  std::vector<int> stk;

  SCC(int n) : n(n), cur(0), cnt(0), adj(n), dfn(n, -1), low(n), bel(n, -1) {}

  void addEdge(int u, int v) { adj[u].push_back(v); }

  void dfs(int u) {
    dfn[u] = low[u] = cur++;
    stk.push_back(u);

    for (auto v : adj[u]) {
      if (dfn[v] == -1) {
        dfs(v);
        low[u] = std::min(low[u], low[v]);
      } else if (bel[v] == -1) {
        low[u] = std::min(low[u], dfn[v]);
      }
    }

    if (dfn[u] == low[u]) {
      int v;
      do {
        v = stk.back();
        stk.pop_back();
        bel[v] = cnt;
      } while (v != u);
      cnt++;
    }
  }

  std::vector<int> work() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) dfs(i);
    }
    return bel;
  }
};

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int w, p;
  std::cin >> w >> p;
  std::vector<P> water(w);
  std::set<P> water_set;
  for (int i = 0; i < w; ++i) {
    std::cin >> water[i].first >> water[i].second;
    water_set.insert({water[i].first, water[i].second});
  }

  SCC scc(2 * p);

  std::vector<F> pipes(p);
  for (int i = 0; i < p; ++i) {
    int s, x2, y2;
    std::cin >> s >> x2 >> y2;
    auto [x1, y1] = water[s - 1];
    pipes[i] = {x1, y1, x2, y2};
  }

  auto ccw = [&](Point a, Point b, Point c) { return 1LL * (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); };
  auto intersect = [&](Point a, Point b, Point c, Point d) {
    i64 ab_c = ccw(a, b, c);
    i64 ab_d = ccw(a, b, d);
    i64 cd_a = ccw(c, d, a);
    i64 cd_b = ccw(c, d, b);

    if (ab_c == 0 && (c.x - a.x) * (c.x - b.x) <= 0 && (c.y - a.y) * (c.y - b.y) <= 0) return true;
    if (ab_d == 0 && (d.x - a.x) * (d.x - b.x) <= 0 && (d.y - a.y) * (d.y - b.y) <= 0) return true;
    if (cd_a == 0 && (a.x - c.x) * (a.x - d.x) <= 0 && (a.y - c.y) * (a.y - d.y) <= 0) return true;
    if (cd_b == 0 && (b.x - c.x) * (b.x - d.x) <= 0 && (b.y - c.y) * (b.y - d.y) <= 0) return true;

    return ab_c * ab_d < 0 && cd_a * cd_b < 0;
  };

  for (int i = 0; i < p; ++i) {
    for (int j = i + 1; j < p; ++j) {
      auto [x1, y1, x2, y2] = pipes[i];
      auto [x3, y3, x4, y4] = pipes[j];
      if (x1 == x3 && y1 == y3) continue;
      if (intersect(Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4))) {
        int u = 2 * i;
        int v = 2 * j;
        scc.addEdge(u, v ^ 1);
        scc.addEdge(v, u ^ 1);
        scc.addEdge(u ^ 1, v);
        scc.addEdge(v ^ 1, u);
      }
    }
  }

  auto bel = scc.work();
  for (int i = 0; i < p; ++i) {
    if (bel[2 * i] == -1) continue;
    if (bel[2 * i] == bel[2 * i + 1]) {
      std::cout << "impossible\n";
      return 0;
    }
  }

  std::cout << "possible\n";
}