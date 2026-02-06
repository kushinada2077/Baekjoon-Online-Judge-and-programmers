#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
  }

  int dfsn_cnt = 0;
  std::stack<int> s;
  std::vector<int> dfsn(n, -1), v_to_scc(n, -1);
  std::vector<bool> finished(n);
  std::vector<std::vector<int>> scc;

  auto dfs = [&](auto&& dfs, int u) -> int {
    dfsn[u] = dfsn_cnt++;
    s.push(u);
    int res = dfsn[u];

    for (auto v : adj[u]) {
      if (dfsn[v] == -1) res = std::min(res, dfs(dfs, v));
      else if (!finished[v]) res = std::min(res, dfsn[v]);
    }

    if (res == dfsn[u]) {
      std::vector<int> tmp;
      while (!s.empty()) {
        int p = s.top();
        s.pop();
        tmp.push_back(p);
        v_to_scc[p] = (int)scc.size();
        finished[p] = true;
        if (p == u) break;
      }

      scc.push_back(tmp);
    }

    return res;
  };

  for (int i = 0; i < n; ++i) {
    if (dfsn[i] == -1) dfs(dfs, i);
  }

  int scc_n = (int)scc.size();
  std::vector<int> indg(scc_n);
  for (int u = 0; u < n; ++u) {
    for (auto v : adj[u]) {
      if (v_to_scc[u] != v_to_scc[v]) indg[v_to_scc[v]]++;
    }
  }

  std::vector<int> ans;
  for (int i = 0; i < scc_n; ++i) {
    if (indg[i] == 0) ans.push_back(i);
  }

  if ((int)ans.size() > 1) {
    std::cout << "Confused\n";
  } else {
    int x = ans.front();
    std::sort(scc[x].begin(), scc[x].end());
    for (auto u : scc[x]) {
      std::cout << u << "\n";
    }
  }

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