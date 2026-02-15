#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

struct Edge {
  int to, c, f;
  Edge() : Edge(0, -1) {}
  Edge(int to, int c) : to(to), c(c), f(0) {}
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n, m;
  std::cin >> n >> m;
  const int MAX_V = n + m + 2;
  int S = n + m, T = S + 1;
  std::vector<int> work(MAX_V), level(MAX_V, -1);
  std::vector<Edge> edges;
  std::vector<std::vector<int>> adj(MAX_V);

  for (int i = 0; i < n; ++i) {
    int u = i, s;
    std::cin >> s;
    for (int j = 0; j < s; ++j) {
      int v;
      std::cin >> v;
      v += n - 1;
      adj[u].push_back((int)edges.size());
      edges.emplace_back(v, 1);
      adj[v].push_back((int)edges.size());
      edges.emplace_back(u, 0);
    }
  }

  for (int i = 0; i < n; ++i) {
    int u = i;
    adj[S].push_back((int)edges.size());
    edges.emplace_back(u, 1);
    adj[u].push_back((int)edges.size());
    edges.emplace_back(S, 0);
  }

  for (int i = 0; i < m; ++i) {
    int u = i + n;
    adj[u].push_back((int)edges.size());
    edges.emplace_back(T, 1);
    adj[T].push_back((int)edges.size());
    edges.emplace_back(u, 0);
  }

  auto bfs = [&]() -> bool {
    std::fill(level.begin(), level.end(), -1);
    level[S] = 0;

    std::queue<int> que;
    que.push(S);

    while (!que.empty()) {
      int u = que.front();
      que.pop();

      for (auto e_num : adj[u]) {
        auto& e = edges[e_num];
        int v = e.to;

        if (level[v] != -1 || e.c - e.f == 0) continue;
        que.push(v);
        level[v] = level[u] + 1;
      }
    }

    return level[T] != -1;
  };

  auto dfs = [&](auto&& dfs, int u, int dest, int flow) -> int {
    if (u == dest) return flow;

    for (int& i = work[u]; i < (int)adj[u].size(); ++i) {
      int e_idx = adj[u][i];
      auto& e = edges[e_idx];
      int v = e.to;

      if (level[v] != level[u] + 1 || e.c - e.f == 0) continue;
      int df = dfs(dfs, v, dest, std::min(e.c - e.f, flow));
      if (df > 0) {
        auto& rev = edges[e_idx ^ 1];
        e.f += df;
        rev.f -= df;
        return df;
      }
    }

    return 0;
  };

  int ans = 0;

  while (bfs()) {
    std::fill(work.begin(), work.end(), 0);
    while (true) {
      int flow = dfs(dfs, S, T, 0x3f3f3f3f);
      if (flow == 0) break;
      ans += flow;
    }
  }

  std::cout << ans << "\n";
}