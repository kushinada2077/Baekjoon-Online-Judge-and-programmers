#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  std::cin >> n >> m;
  std::vector<int> atm_cash(n);
  std::vector<bool> has_restaurant(n);
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u - 1].push_back(v - 1);
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> atm_cash[i];
  }

  int s, p;
  std::cin >> s >> p;
  s--;
  for (int i = 0; i < p; ++i) {
    int x;
    std::cin >> x;
    has_restaurant[x - 1] = true;
  }

  int dfsn_cnt = 0;
  std::stack<int> stack;
  std::vector<int> dfsn(n, -1), v_to_scc(n, -1);
  std::vector<bool> finished(n), scc_has_restuarant;
  std::vector<std::vector<int>> scc;
  std::vector<int> scc_cash_sum;

  auto dfs = [&](auto&& dfs, int u) -> int {
    dfsn[u] = dfsn_cnt++;
    stack.push(u);
    int res = dfsn[u];

    for (auto v : adj[u]) {
      if (dfsn[v] == -1) res = std::min(res, dfs(dfs, v));
      else if (!finished[v]) res = std::min(res, dfsn[v]);
    }

    if (res == dfsn[u]) {
      std::vector<int> cur_scc;
      int sum = 0;
      bool has = false;
      while (!stack.empty()) {
        int p = stack.top();
        stack.pop();
        cur_scc.push_back(p);
        finished[p] = true;
        v_to_scc[p] = (int)scc.size();
        sum += atm_cash[p];
        if (has_restaurant[p] == true) has = true;
        if (p == u) break;
      }
      scc.push_back(cur_scc);
      scc_cash_sum.push_back(sum);
      scc_has_restuarant.push_back(has);
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

  std::queue<int> q;
  for (int i = 0; i < scc_n; ++i) {
    if (indg[i] == 0) {
      q.push(i);
    }
  }

  int scc_s = v_to_scc[s];
  std::vector<int> dp(scc_n);
  std::vector<bool> reachable(scc_n);
  while (!q.empty()) {
    int scc_u = q.front();
    q.pop();
    if (scc_u == scc_s) {
      dp[scc_s] = scc_cash_sum[scc_s];
      reachable[scc_s] = true;
    }

    for (auto u : scc[scc_u]) {
      for (auto v : adj[u]) {
        int scc_v = v_to_scc[v];
        if (scc_u == scc_v) continue;
        if (reachable[scc_u]) {
          dp[scc_v] = std::max(dp[scc_v], dp[scc_u] + scc_cash_sum[scc_v]);
          reachable[scc_v] = true;
        }
        if (--indg[scc_v] == 0) {
          q.push(scc_v);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < scc_n; ++i) {
    if (scc_has_restuarant[i]) ans = std::max(ans, dp[i]);
  }

  std::cout << ans << "\n";
}