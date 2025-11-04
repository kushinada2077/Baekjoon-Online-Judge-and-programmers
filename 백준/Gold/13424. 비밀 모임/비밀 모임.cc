#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector dist(n + 1, std::vector<int>(n + 1, 0x3f3f3f3f));
  for (int i = 1; i <= n; ++i) dist[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    dist[u][v] = dist[v][u] = c;
  }

  int k;
  std::cin >> k;
  std::vector<int> f(k);
  for (int i = 0; i < k; ++i) std::cin >> f[i];

  for (int k = 1; k <= n; ++k) {
    for (int u = 1; u <= n; ++u) {
      for (int v = 1; v <= n; ++v) {
        if (dist[u][v] > dist[u][k] + dist[k][v]) dist[u][v] = dist[u][k] + dist[k][v];
      }
    }
  }

  int ans_dist = 0x3f3f3f3f, ans_num = n + 1;

  for (int v = 1; v <= n; ++v) {
    int tot = 0;
    for (auto u : f) {
      tot += dist[u][v];
    }

    if (ans_dist > tot) {
      ans_dist = tot;
      ans_num = v;
    }
  }

  std::cout << ans_num << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) solve();
}