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

  struct Edge {
    int from;
    int to;
    T cap;
    T flow;
  };

  std::vector<Edge> edges() {
    std::vector<Edge> a;
    for (int i = 0; i < int(e.size()); i += 2) {
      Edge x;
      x.from = e[i ^ 1].to;
      x.to = e[i].to;
      x.cap = e[i].cap + e[i ^ 1].cap;
      x.flow = e[i ^ 1].cap;
      a.push_back(x);
    }
    return a;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  const int INF = 0x3f3f3f3f;
  int tc;
  std::cin >> tc;
  MaxFlow<int> mf;
  while (tc--) {
    [&] {
      int n;
      std::cin >> n;
      const int MAX = 2 * n + 2, S = MAX - 2, T = MAX - 1;
      int n_safe = 0, n_dangerous = 0;
      std::vector<int> a(n);
      std::vector<std::string> adj(n);
      for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
      }
      for (int i = 0; i < n; ++i) {
        std::cin >> adj[i];
      }

      auto init_mf = [&](int mid) {
        mf.init(MAX);
        n_safe = n_dangerous = 0;
        for (int i = 0; i < n; ++i) {
          if (a[i] > 0) {
            mf.addEdge(S, 2 * i, a[i]);
          }
        }

        for (int i = 0; i < n; ++i) {
          bool safe = true;
          for (int j = 0; j < n; ++j) {
            char c = adj[i][j];
            if (a[i] == 0) continue;
            if (c == 'Y') {
              if (a[j] == 0) {
                safe = false;
              } else {
                mf.addEdge(2 * i, 2 * j + 1, INF);
              }
            }
          }

          if (a[i] != 0) {
            mf.addEdge(2 * i, 2 * i + 1, INF);
            if (safe) {
              mf.addEdge(2 * i + 1, T, 1);
              n_safe++;
            } else {
              mf.addEdge(2 * i + 1, T, mid);
              n_dangerous++;
            }
          }
        }
      };

      auto ok = [&](int mid) -> bool {
        init_mf(mid);
        bool ret = false;
        auto f = mf.flow(S, T);
        if (1LL * f >= 1LL * mid * n_dangerous + n_safe) {
          ret = true;
        }
        return ret;
      };

      int lo = 0, hi = INF;
      while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) lo = mid;
        else hi = mid;
      }
      std::println("{}", lo);
    }();
  }
}