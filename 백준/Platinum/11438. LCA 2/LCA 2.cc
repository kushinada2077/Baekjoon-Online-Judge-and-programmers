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
  const int MAX = 17;
  int n;
  std::cin >> n;
  std::vector adj(n, std::vector<int>());
  std::vector<int> d(n, -1);
  std::vector p(MAX, std::vector<int>(n, -1));
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }

  std::queue<int> q;
  q.push(0);
  d[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (p[0][u] == v) continue;
      q.push(v);
      p[0][v] = u;
      d[v] = d[u] + 1;
    }
  }

  for (int k = 1; k < MAX; ++k) {
    for (int i = 0; i < n; ++i) {
      p[k][i] = p[k - 1][p[k - 1][i]];
    }
  }

  auto LCA = [&](int u, int v) -> int {
    if (d[u] < d[v]) std::swap(u, v);
    int diff = d[u] - d[v];

    for (int cnt = 0; diff; ++cnt, diff /= 2) {
      if (diff % 2 == 0) continue;
      u = p[cnt][u];
    }

    if (u == v) return u;

    int k = MAX - 1;
    while (k >= 0 && p[k][u] == p[k][v]) k--;

    for (; k >= 0; --k) {
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
    std::cout << LCA(u - 1, v - 1) + 1 << "\n";
  }
}