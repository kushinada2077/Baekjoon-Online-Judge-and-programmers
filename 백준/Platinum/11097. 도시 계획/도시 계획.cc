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

void solve() {
  int n;
  std::cin >> n;
  SCC scc(n);
  char x;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> x;
      if (x == '0' || i == j) continue;
      scc.addEdge(i, j);
    }
  }

  auto bel = scc.work();
  int scc_n = scc.cnt;
  std::vector groups(scc_n, std::vector<int>());
  for (int i = 0; i < n; ++i) {
    groups[bel[i]].push_back(i);
  }

  std::vector<P> ans;
  for (int i = 0; i < scc_n; ++i) {
    int sz = (int)groups[i].size();
    if (sz == 1) continue;
    for (int j = 0; j < sz; ++j) {
      ans.push_back({groups[i][j], groups[i][(j + 1) % sz]});
    }
  }

  std::vector scc_adj(scc_n, std::vector<bool>(scc_n));
  for (int u = 0; u < n; ++u) {
    for (auto v : scc.adj[u]) {
      if (bel[u] == bel[v] || scc_adj[bel[u]][bel[v]]) continue;
      scc_adj[bel[u]][bel[v]] = true;
    }
  }

  for (int k = 0; k < scc_n; ++k) {
    for (int i = 0; i < scc_n; ++i) {
      for (int j = 0; j < scc_n; ++j) {
        if (scc_adj[i][k] && scc_adj[k][j] && scc_adj[i][j]) scc_adj[i][j] = false;
      }
    }
  }

  for (int i = 0; i < scc_n; ++i) {
    for (int j = 0; j < scc_n; ++j) {
      if (scc_adj[i][j]) {
        ans.push_back({groups[i].front(), groups[j].front()});
      }
    }
  }

  std::cout << (int)ans.size() << "\n";
  for (auto [u, v] : ans) std::cout << u + 1 << " " << v + 1 << "\n";
  std::cout << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}