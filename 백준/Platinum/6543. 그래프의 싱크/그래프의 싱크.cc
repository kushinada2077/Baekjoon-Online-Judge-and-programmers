#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

std::pair<std::vector<std::vector<int>>, std::vector<int>> make_scc(int n, int m, std::vector<std::vector<int>>& adj) {
  int dfsn_cnt = 0;
  std::stack<int> S;
  std::vector<int> dfsn(n, -1), v_to_scc(n, -1);
  std::vector<bool> finished(n);
  std::vector<std::vector<int>> scc;

  auto dfs = [&](auto&& dfs, int u) -> int {
    dfsn[u] = dfsn_cnt++;
    S.push(u);
    int res = dfsn[u];

    for (auto v : adj[u]) {
      if (dfsn[v] == -1) res = std::min(res, dfs(dfs, v));
      else if (!finished[v]) res = std::min(res, dfsn[v]);
    }

    if (res == dfsn[u]) {
      std::vector<int> cur_scc;
      while (!S.empty()) {
        int x = S.top();
        S.pop();
        cur_scc.push_back(x);
        v_to_scc[x] = (int)scc.size();
        finished[x] = true;
        if (x == u) break;
      }
      scc.push_back(cur_scc);
    }

    return res;
  };

  for (int i = 0; i < n; ++i) {
    if (dfsn[i] == -1) dfs(dfs, i);
  }

  return {scc, v_to_scc};
}
bool solve() {
  int n;
  std::cin >> n;
  if (n == 0) return false;
  int m;
  std::cin >> m;
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u - 1].push_back(v - 1);
  }

  auto [scc, v_to_scc] = make_scc(n, m, adj);
  int scc_n = (int)scc.size();
  std::vector<int> outdg(scc_n);
  for (int u = 0; u < n; ++u) {
    for (auto v : adj[u]) {
      if (v_to_scc[u] != v_to_scc[v]) outdg[v_to_scc[u]]++;
    }
  }

  std::vector<int> ans;
  for (int i = 0; i < scc_n; ++i) {
    if (outdg[i] == 0) {
      for (auto x : scc[i]) {
        ans.push_back(x);
      }
    }
  }

  std::sort(ans.begin(), ans.end());
  for (auto x : ans) std::cout << x + 1 << " ";
  std::cout << "\n";
  return true;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  while (solve());
}