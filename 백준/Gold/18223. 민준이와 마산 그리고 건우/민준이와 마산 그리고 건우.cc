#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int v, e, p;
  std::cin >> v >> e >> p;
  std::vector adj(v + 1, std::vector<P>());
  for (int i = 0; i < e; ++i) {
    int U, V, C;
    std::cin >> U >> V >> C;
    adj[U].push_back({V, C});
    adj[V].push_back({U, C});
  }

  auto djikstra = [&](int p) {
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    std::vector<int> ret(v + 1, 0x3f3f3f3f);
    pq.push({0, p});
    ret[p] = 0;

    while (!pq.empty()) {
      auto [dis, u] = pq.top();
      pq.pop();
      if (ret[u] != dis) continue;
      for (auto [v, c] : adj[u]) {
        if (ret[v] > ret[u] + c) {
          ret[v] = ret[u] + c;
          pq.push({ret[v], v});
        }
      }
    }

    return ret;
  };

  auto d1 = djikstra(1);
  auto d2 = djikstra(p);

  if (d1[v] == d1[p] + d2[v]) std::cout << "SAVE HIM\n";
  else std::cout << "GOOD BYE\n";
}