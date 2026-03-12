#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using TP = std::tuple<int, int, int>;

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
    c *= 2;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  const int S = 0;
  const double INF = 0x3f3f3f3f;
  auto djikstra = [&](int s) -> std::vector<int> {
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    std::vector<int> dist(n, INF);
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (dist[u] != d) {
        continue;
      }
      for (auto [v, c] : adj[u]) {
        if (dist[v] > dist[u] + c) {
          dist[v] = dist[u] + c;
          pq.push({dist[v], v});
        }
      }
    }
    return dist;
  };

  auto w_djikstra = [&](int s) -> std::vector<std::vector<int>> {
    std::vector dist(n, std::vector<int>(2, INF));
    std::priority_queue<TP, std::vector<TP>, std::greater<TP>> pq;
    dist[s][0] = 0;
    pq.push({0, s, 0});
    while (!pq.empty()) {
      auto [d, u, o] = pq.top();
      pq.pop();
      if (d != dist[u][o]) {
        continue;
      }
      for (auto [v, c] : adj[u]) {
        if (o == 0) {
          c /= 2;
        } else {
          c *= 2;
        }
        if (dist[v][o ^ 1] > dist[u][o] + c) {
          dist[v][o ^ 1] = dist[u][o] + c;
          pq.push({dist[v][o ^ 1], v, o ^ 1});
        }
      }
    }
    return dist;
  };

  const auto& fox = djikstra(S);
  const auto& wolf = w_djikstra(S);
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (fox[i] < std::min(wolf[i][0], wolf[i][1])) {
      ans++;
    }
  }
  std::println("{}", ans);
}