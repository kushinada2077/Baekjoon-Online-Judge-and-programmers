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
  std::vector adj(n, std::vector<P>());
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    u--;
    v--;
    adj[u].push_back({c, v});
    adj[v].push_back({c, u});
  }

  const int INF = 0x3f3f3f3f;
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  std::vector<int> d(n, INF);
  std::vector<int> ans(n);
  d[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [dist, u] = pq.top();
    pq.pop();
    if (d[u] != dist) continue;
    for (auto [c, v] : adj[u]) {
      if (d[v] > d[u] + c) {
        d[v] = d[u] + c;
        pq.push({d[v], v});
        ans[v] = u;
      }
    }
  }

  std::cout << n - 1 << "\n";
  for (int i = 1; i < n; ++i) {
    std::cout << i + 1 << " " << ans[i] + 1 << "\n";
  }
}