#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

struct SCC {
  int n;
  int cur, cnt;
  std::vector<std::vector<int>> adj;
  std::vector<int> dfn, low, bel;
  std::vector<int> stk;

  SCC(int n) : n(n), cur(0), cnt(0), adj(n), dfn(n, -1), low(n), bel(n, -1) {}

  void addEdge(int u, int v) { adj[u].push_back(v); }

  void dfs(int u) {
    dfn[u] = low[u] = cur++;
    stk.push_back(u);

    for (auto v : adj[u]) {
      if (dfn[v] == -1) {
        dfs(v);
        low[u] = std::min(low[u], low[v]);
      } else if (bel[v] == -1) {
        low[u] = std::min(low[u], dfn[v]);
      }
    }

    if (dfn[u] == low[u]) {
      int v;
      do {
        v = stk.back();
        stk.pop_back();
        bel[v] = cnt;
      } while (v != u);
      cnt++;
    }
  }

  std::vector<int> work() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) dfs(i);
    }
    return bel;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int t;
  std::cin >> t;
  while (t--) {
    [&] {
      int n, m, k;
      std::cin >> n >> m >> k;
      SCC scc(2 * (n + m));
      int offset = 2 * n;
      for (int i = 0; i < k; ++i) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        if (a == c && b == d) continue;
        int u1 = 2 * a;
        int v1 = offset + 2 * d;
        int u2 = offset + 2 * b;
        int v2 = 2 * c;
        if (a > c) {
          u2 ^= 1;
          v1 ^= 1;
        }
        if (b > d) {
          u1 ^= 1;
          v2 ^= 1;
        }

        if (a == c) {
          scc.addEdge(u1 ^ 1, u1);
        } else if (b == d) {
          scc.addEdge(u2 ^ 1, u2);
        } else {
          scc.addEdge(u2 ^ 1, u1);
          scc.addEdge(u1 ^ 1, u2);

          scc.addEdge(v2 ^ 1, v1);
          scc.addEdge(v1 ^ 1, v2);

          scc.addEdge(v2 ^ 1, u1);
          scc.addEdge(u1 ^ 1, v2);

          scc.addEdge(u2 ^ 1, v1);
          scc.addEdge(v1 ^ 1, u2);
        }
      }

      auto bel = scc.work();

      for (int i = 0; i < n + m; ++i) {
        if (bel[2 * i] == bel[2 * i + 1]) {
          std::cout << "No\n";
          return;
        }
      }

      std::cout << "Yes\n";
    }();
  }
}