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
  int n, m;
  std::cin >> n >> m;
  std::vector adj(n, std::vector<int>());
  std::vector<int> indg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    indg[v - 1]++;
  }

  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (indg[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    std::cout << u + 1 << " ";

    for (auto v : adj[u]) {
      if (--indg[v] == 0) q.push(v);
    }
  }
}