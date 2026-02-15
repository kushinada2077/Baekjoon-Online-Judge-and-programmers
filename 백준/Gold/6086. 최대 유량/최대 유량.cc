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
  int m;
  std::cin >> m;

  auto c_to_i = [](char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
  };

  const int MAX = 52;
  std::vector adj(MAX, std::vector<int>());
  std::vector c(MAX, std::vector<int>(MAX)), f(MAX, std::vector<int>(MAX));
  for (int i = 0; i < m; ++i) {
    char a, b;
    int w;
    std::cin >> a >> b >> w;
    int u = c_to_i(a);
    int v = c_to_i(b);
    c[u][v] = c[v][u] += w;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0, S = c_to_i('A'), E = c_to_i('Z');

  while (true) {
    std::vector<int> prev(MAX, -1);
    std::queue<int> Q;
    Q.push(S);

    while (!Q.empty() && prev[E] == -1) {
      int u = Q.front();
      Q.pop();
      for (auto v : adj[u]) {
        if (c[u][v] - f[u][v] > 0 && prev[v] == -1) {
          Q.push(v);
          prev[v] = u;
          if (v == E) break;
        }
      }
    }

    if (prev[E] == -1) break;

    int flow = 0x3f3f3f3f;
    for (int i = E; i != S; i = prev[i]) {
      flow = std::min(flow, c[prev[i]][i] - f[prev[i]][i]);
    }
    for (int i = E; i != S; i = prev[i]) {
      f[prev[i]][i] += flow;
      f[i][prev[i]] -= flow;
    }

    ans += flow;
  }

  std::cout << ans << "\n";
}