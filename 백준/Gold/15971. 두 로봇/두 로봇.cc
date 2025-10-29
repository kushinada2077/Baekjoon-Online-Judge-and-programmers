#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, s1, s2;
  std::cin >> n >> s1 >> s2;
  std::vector adj(n + 1, std::vector<P>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  constexpr int INF = 0x3f3f3f3f;
  auto djikstra = [&](int st) {
    std::vector<int> dist(n + 1, INF);
    dist[st] = 0;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, st});

    while (!pq.empty()) {
      auto [cur_d, u] = pq.top();
      pq.pop();
      if (dist[u] != cur_d) continue;

      for (auto [v, c] : adj[u]) {
        if (dist[v] > dist[u] + c) {
          dist[v] = dist[u] + c;
          pq.push({dist[v], v});
        }
      }
    }

    return dist;
  };

  auto d1 = djikstra(s1);
  auto d2 = djikstra(s2);
  int ans = INT_MAX;

  for (int u = 1; u <= n; ++u) {
    for (auto [v, c] : adj[u]) {
      ans = std::min({ans, d1[u] + d2[u], d1[v] + d2[v], d1[u] + d2[v], d1[v] + d2[u]});
    }
  }

  if (n == 1) ans = 0;
  std::cout << ans << "\n";
}