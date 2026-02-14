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
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1, -1), d(n + 1, -1);
  std::vector adj(n + 1, std::vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::queue<int> q;
  q.push(1);
  d[1] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (p[u] == v) continue;
      q.push(v);
      p[v] = u;
      d[v] = d[u] + 1;
    }
  }

  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    if (d[u] < d[v]) std::swap(u, v);
    while (d[u] != d[v]) u = p[u];
    while (u != v) {
      u = p[u];
      v = p[v];
    }

    std::cout << u << "\n";
  }
}