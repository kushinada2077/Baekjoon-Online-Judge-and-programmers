#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

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

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  while (std::cin >> n >> m) {
    [&] {
      SCC scc(2 * n);
      scc.addEdge(1, 0);
      for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u = 2 * (std::abs(u) - 1) + (u < 0);
        v = 2 * (std::abs(v) - 1) + (v < 0);
        scc.addEdge(u ^ 1, v);
        scc.addEdge(v ^ 1, u);
      }

      auto bel = scc.work();
      for (int i = 0; i < n; ++i) {
        if (bel[2 * i] == bel[2 * i + 1]) {
          std::cout << "no\n";
          return;
        }
      }

      std::cout << "yes\n";
    }();
  }
}