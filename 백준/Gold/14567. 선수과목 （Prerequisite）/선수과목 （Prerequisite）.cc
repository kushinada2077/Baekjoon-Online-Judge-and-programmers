#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> indg(n);
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    indg[b]++;
  }

  std::queue<int> q;
  std::vector<int> res(n, -1);
  for (int i = 0; i < n; ++i) {
    if (indg[i] == 0) {
      q.push(i);
      res[i] = 1;
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (--indg[v] == 0) {
        q.push(v);
        res[v] = res[u] + 1;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << res[i] << " \n"[i == n - 1];
  }
}