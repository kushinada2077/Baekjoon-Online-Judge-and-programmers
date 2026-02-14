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
  const int MAX = 16;
  int n;
  std::cin >> n;
  std::vector<int> dist(n, -1), d(n, -1);
  std::vector adj(n, std::vector<P>());
  std::vector p(MAX, std::vector<int>(n, -1));
  for (int i = 0; i < n - 1; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    adj[u - 1].push_back({v - 1, c});
    adj[v - 1].push_back({u - 1, c});
  }

  std::queue<int> q;
  q.push(0);
  d[0] = dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto [v, c] : adj[u]) {
      if (p[0][u] == v) continue;
      q.push(v);
      p[0][v] = u;
      d[v] = d[u] + 1;
      dist[v] = dist[u] + c;
    }
  }

  for (int k = 1; k < MAX; ++k) {
    for (int i = 0; i < n; ++i) {
      if (p[k - 1][i] == -1) continue;
      p[k][i] = p[k - 1][p[k - 1][i]];
    }
  }

  auto LCA = [&](int u, int v) -> int {
    if (d[u] < d[v]) std::swap(u, v);
    int diff = d[u] - d[v];

    for (int k = 0; diff; ++k, diff /= 2) {
      if (diff % 2 == 0) continue;
      u = p[k][u];
    }

    if (u == v) return u;

    for (int k = MAX - 1; k >= 0; --k) {
      if (p[k][u] == p[k][v]) continue;
      u = p[k][u];
      v = p[k][v];
    }

    return p[0][u];
  };

  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    int m = LCA(u - 1, v - 1);
    int d1 = dist[u - 1] - dist[m];
    int d2 = dist[v - 1] - dist[m];
    std::cout << d1 + d2 << "\n";
  }
}