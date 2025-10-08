#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector adj(n, std::vector<P>());
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--;
    v--;
    adj[u].push_back({v, w});
  }

  const i64 INF = 1e18;
  std::vector<i64> dist(n, INF);
  dist[0] = 0;
  bool cycle = false;
  for (int i = 0; i < n; ++i) {
    for (int u = 0; u < n; ++u) {
      for (auto [v, w] : adj[u]) {
        if (dist[u] != INF && dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          if (i == n - 1) cycle = true;
        }
      }
    }
  }

  if (cycle) std::cout << "-1\n";
  else {
    for (int i = 1; i < n; ++i) {
      if (dist[i] == INF) dist[i] = -1;
      std::cout << dist[i] << "\n";
    }
  }
}