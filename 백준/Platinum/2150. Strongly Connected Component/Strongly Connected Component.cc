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
  int v, e;
  std::cin >> v >> e;
  std::vector adj(v, std::vector<int>());
  for (int i = 0; i < e; ++i) {
    int a, b;
    std::cin >> a >> b;
    adj[a - 1].push_back(b - 1);
  }

  std::stack<int> s;
  int dfsn_cnt = 0;
  std::vector<int> dfsn(v, -1);
  std::vector<std::vector<int>> scc;
  std::vector<bool> finished(v);
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
        finished[p] = true;
        tmp.push_back(p);
        if (p == u) break;
      }

      std::sort(tmp.begin(), tmp.end());
      scc.push_back(tmp);
    }

    return res;
  };

  for (int i = 0; i < v; ++i) {
    if (dfsn[i] == -1) dfs(dfs, i);
  }

  std::sort(scc.begin(), scc.end(), [&](auto& a, auto& b) { return a.front() < b.front(); });
  std::cout << scc.size() << "\n";
  for (auto& curSCC : scc) {
    for (auto u : curSCC) std::cout << u + 1 << " ";
    std::cout << "-1\n";
  }
}