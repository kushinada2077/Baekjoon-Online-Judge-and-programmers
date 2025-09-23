#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
void solve() {
  int n, d, c;
  std::cin >> n >> d >> c;
  c--;
  std::vector adj(n, std::vector<P>());
  std::vector<int> dis(n, INF);

  for (int i = 0; i < d; ++i) {
    int a, b, s;
    std::cin >> a >> b >> s;
    a--;
    b--;
    adj[b].push_back({a, s});
  }

  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  pq.push({0, c});
  dis[c] = 0;

  while (!pq.empty()) {
    auto [dis_u, u] = pq.top();
    pq.pop();
    if (dis[u] != dis_u) continue;

    for (auto [v, s] : adj[u]) {
      if (dis[u] + s < dis[v]) {
        dis[v] = dis[u] + s;
        pq.push({dis[v], v});
      }
    }
  }

  int num = 0, time = 0;
  for (int i = 0; i < n; ++i) {
    if (dis[i] != INF) {
      num++;
      time = std::max(time, dis[i]);
    }
  }

  std::cout << num << " " << time << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}