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
  int m;
  std::cin >> m;
  std::map<std::string, int> vs;
  std::vector<P> queries;
  std::string s;
  for (int i = 0; i < m; ++i) {
    int x;
    std::cin >> s >> x;
    if (!vs.contains(s)) {
      vs[s] = (int)vs.size();
    }
    int v = vs[s];
    for (int j = 0; j < x; ++j) {
      std::cin >> s;
      if (!vs.contains(s)) {
        vs[s] = (int)vs.size();
      }
      int u = vs[s];
      queries.push_back({u, v});
    }
  }

  int n = (int)vs.size();
  SCC scc(n);

  for (auto [u, v] : queries) {
    scc.addEdge(u, v);
  }

  std::cin >> s;
  int st = vs[s];
  auto bel = scc.work();
  int scc_n = scc.cnt;
  std::vector<i64> dp(n, 1);
  std::vector groups(scc_n, std::vector<int>());

  for (int i = 0; i < n; ++i) {
    groups[bel[i]].push_back(i);
  }
  for (int i = scc_n - 1; i >= 0; --i) {
    for (auto u : groups[i]) {
      for (auto v : scc.adj[u]) {
        int nxt_i = bel[v];
        if (nxt_i != i) dp[v] += dp[u];
      }
    }
  }

  std::cout << dp[st] << "\n";
}