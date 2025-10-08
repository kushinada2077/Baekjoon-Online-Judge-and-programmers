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
    w *= -1;
    adj[u].push_back({v, w});
  }

  const i64 INF = 1e18;
  std::vector<i64> dist(n, INF);
  std::vector<int> pre(n, -1);
  std::queue<int> q;
  dist[0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int u = 0; u < n; ++u) {
      for (auto [v, w] : adj[u]) {
        if (dist[u] != INF && dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pre[v] = u;
          if (i == n - 1) q.push(v);
        }
      }
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, w] : adj[u]) {
      if (dist[v] == -INF) continue;
      dist[v] = -INF;
    }
  }

  if (dist[n - 1] == INF || dist[n - 1] == -INF) std::cout << "-1\n";
  else {
    int cur = n - 1;
    std::vector<int> ans;
    while (cur != -1) {
      ans.push_back(cur + 1);
      cur = pre[cur];
    }

    for (auto it = ans.rbegin(); it != ans.rend(); ++it) std::cout << *it << " ";
  }
}