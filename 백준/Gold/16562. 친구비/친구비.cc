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
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> d(n, -1);
  auto bfs = [&](int S) -> int {
    int ret = 0x3f3f3f3f;
    std::queue<int> que;
    d[S] = 0;
    que.push(S);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      ret = std::min(ret, a[u]);
      for (auto v : adj[u]) {
        if (d[v] == -1) {
          d[v] = d[u] + 1;
          que.push(v);
        }
      }
    }
    return ret;
  };

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (d[i] == -1) {
      ans += bfs(i);
    }
  }

  if (k >= ans) {
    std::println("{}", ans);
  } else {
    std::println("Oh no");
  }
}