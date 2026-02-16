#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

template <class T>
struct MaxFlow {
  struct _Edge {
    int to;
    T cap;
    _Edge(int to, T cap) : to(to), cap(cap) {}
  };

  int n;
  std::vector<_Edge> e;
  std::vector<std::vector<int>> g;
  std::vector<int> cur, h;

  MaxFlow() {}
  MaxFlow(int n) { init(n); }

  void init(int n) {
    this->n = n;
    e.clear();
    g.assign(n, {});
    cur.resize(n);
    h.resize(n);
  }

  bool bfs(int s, int t) {
    h.assign(n, -1);
    std::queue<int> que;
    h[s] = 0;
    que.push(s);
    while (!que.empty()) {
      const int u = que.front();
      que.pop();
      for (int i : g[u]) {
        auto [v, c] = e[i];
        if (c > 0 && h[v] == -1) {
          h[v] = h[u] + 1;
          if (v == t) {
            return true;
          }
          que.push(v);
        }
      }
    }
    return false;
  }

  T dfs(int u, int t, T f) {
    if (u == t) {
      return f;
    }
    auto r = f;
    for (int& i = cur[u]; i < int(g[u].size()); ++i) {
      const int j = g[u][i];
      auto [v, c] = e[j];
      if (c > 0 && h[v] == h[u] + 1) {
        auto a = dfs(v, t, std::min(r, c));
        e[j].cap -= a;
        e[j ^ 1].cap += a;
        r -= a;
        if (r == 0) {
          return f;
        }
      }
    }
    return f - r;
  }
  void addEdge(int u, int v, T c) {
    g[u].push_back(e.size());
    e.emplace_back(v, c);
    g[v].push_back(e.size());
    e.emplace_back(u, 0);
  }

  T flow(int s, int t) {
    T ans = 0;
    while (bfs(s, t)) {
      cur.assign(n, 0);
      ans += dfs(s, t, std::numeric_limits<T>::max());
    }
    return ans;
  }

  std::vector<bool> minCut() {
    std::vector<bool> c(n);
    for (int i = 0; i < n; ++i) {
      c[i] = (h[i] != -1);
    }
    return c;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  const int INF = 0x3f3f3f3f;
  int n;
  std::cin >> n;
  const int S = n, T = n + 1;
  MaxFlow<int> M(n + 2);
  std::vector<int> team(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> team[i];
    if (team[i] == 1) M.addEdge(S, i, INF);
    else if (team[i] == 2) M.addEdge(i, T, INF);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      std::cin >> x;
      if (x == 0) continue;
      M.addEdge(i, j, x);
    }
  }

  std::cout << M.flow(S, T) << "\n";
  auto c = M.minCut();
  for (int i = 0; i < n; ++i) {
    if (c[i]) std::cout << i + 1 << " ";
  }
  std::cout << "\n";
  for (int i = 0; i < n; ++i) {
    if (!c[i]) std::cout << i + 1 << " ";
  }
  std::cout << "\n";
}