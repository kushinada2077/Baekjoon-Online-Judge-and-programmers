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
  int n;
  std::cin >> n;
  std::vector adj(n, std::vector<int>());
  for (int u = 0; u < n; ++u) {
    int v;
    std::cin >> v;
    if (u + v < n) adj[u].push_back(u + v);
    if (u - v >= 0) adj[u].push_back(u - v);
  }
  int s;
  std::cin >> s;

  std::vector<bool> vis(n);
  std::queue<int> q;
  q.push(s - 1);
  vis[s - 1] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (vis[v]) continue;
      q.push(v);
      vis[v] = true;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) ans += vis[i];
  std::cout << ans << "\n";
}