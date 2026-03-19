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
  int n, k, m;
  std::cin >> n >> k >> m;
  std::vector<int> S, T;
  std::vector bel(n, std::vector<int>());
  std::vector com(m, std::vector<int>(k));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      std::cin >> com[i][j];
      com[i][j]--;
      bel[com[i][j]].push_back(i);
      if (com[i][j] == 0) {
        S.push_back(i);
      }
      if (com[i][j] == n - 1) {
        T.push_back(i);
      }
    }
  }

  std::queue<int> que;
  std::vector<int> d(m, -1), vis(n);
  for (auto u : S) {
    d[u] = 1;
    que.push(u);
  }

  while (!que.empty()) {
    auto u = que.front();
    que.pop();
    for (auto x : com[u]) {
      if (vis[x]) {
        continue;
      }
      vis[x] = 1;
      for (auto v : bel[x]) {
        if (d[v] == -1) {
          d[v] = d[u] + 1;
          que.push(v);
        }
      }
    }
  }

  int ans = 0x3f3f3f3f;
  for (auto x : T) {
    if (d[x] != -1) {
      ans = std::min(ans, d[x]);
    }
  }

  if (ans == 0x3f3f3f3f) {
    ans = -2;
  }
  if (n == 1) {
    ans = 0;
  }
  std::println("{}", ans + 1);
}