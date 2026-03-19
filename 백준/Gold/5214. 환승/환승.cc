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
  int n, k, m;
  std::cin >> n >> k >> m;
  const int N = n + m;
  std::vector adj(N, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    int v = i + n;
    for (int j = 0; j < k; ++j) {
      int u;
      std::cin >> u;
      u--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  std::queue<int> que;
  std::vector<int> d(N, -1);
  d[0] = 1;
  que.push(0);
  while (!que.empty()) {
    auto u = que.front();
    que.pop();
    for (auto v : adj[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + (u < n ? 0 : 1);
        que.push(v);
      }
    }
  }

  std::println("{}", d[n - 1]);
}