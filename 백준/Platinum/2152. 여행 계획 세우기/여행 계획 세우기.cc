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
  int n, m, s, t;
  std::cin >> n >> m >> s >> t;
  s--;
  t--;

  SCC scc(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    scc.addEdge(u - 1, v - 1);
  }

  auto bel = scc.work();
  int scc_n = scc.cnt;

  std::vector<std::vector<int>> groups(scc_n);
  for (int i = 0; i < n; ++i) {
    groups[scc.bel[i]].push_back(i);
  }

  std::vector<int> dp(scc_n);
  std::vector<bool> reachable(scc_n);
  for (int i = 0; i < scc_n; ++i) {
    dp[i] = (int)groups[i].size();
  }
  reachable[scc.bel[s]] = true;
  for (int i = scc_n - 1; i >= 0; --i) {
    if (!reachable[i]) continue;

    for (auto u : groups[i]) {
      for (auto v : scc.adj[u]) {
        int nxt_i = scc.bel[v];
        if (i == nxt_i) continue;
        dp[nxt_i] = std::max(dp[nxt_i], dp[i] + (int)groups[nxt_i].size());
        reachable[nxt_i] = true;
      }
    }
  }

  if (!reachable[scc.bel[t]]) std::cout << "0\n";
  else std::cout << dp[scc.bel[t]] << "\n";
}