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
  std::vector<int> energy(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> energy[i];
  }

  std::vector adj(n, std::vector<P>());
  std::vector<int> p(n, -1), d(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    adj[a - 1].push_back({b - 1, c});
    adj[b - 1].push_back({a - 1, c});
  }

  const int MAX = 17;
  std::vector dp(MAX, std::vector<int>(n, -1));
  std::vector cost(MAX, std::vector<int>(n, -1));

  std::queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto [v, c] : adj[u]) {
      if (p[u] == v) continue;
      q.push(v);
      p[v] = u;
      d[v] = d[u] + 1;
      dp[0][v] = u;
      cost[0][v] = c;
    }
  }

  for (int k = 1; k < MAX; ++k) {
    for (int i = 0; i < n; ++i) {
      if (dp[k - 1][i] == -1) continue;
      dp[k][i] = dp[k - 1][dp[k - 1][i]];
      cost[k][i] = cost[k - 1][dp[k - 1][i]] + cost[k - 1][i];
    }
  }

  for (int i = 0; i < n; ++i) {
    int cur = i, cur_e = energy[i];
    for (int k = MAX - 1; k >= 0; --k) {
      if (dp[k][cur] == -1) continue;
      if (cur_e >= cost[k][cur]) {
        cur_e -= cost[k][cur];
        cur = dp[k][cur];
      }
    }

    std::cout << cur + 1 << "\n";
  }
}