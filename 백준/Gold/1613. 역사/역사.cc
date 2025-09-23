#include <bits/stdc++.h>
using i64 = long long;

constexpr int INF = 0x3f3f3f3f;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector adj(n, std::vector<int>()), dist(n, std::vector<int>(n, 0));

  for (int i = 0; i < k; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    dist[u][v] = 1;
  }

  for (int p = 0; p < n; ++p) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][j] == 0 && dist[i][p] == 1 && dist[p][j] == 1) {
          dist[i][j] = 1;
        }
      }
    }
  }

  int s;
  std::cin >> s;
  for (int i = 0; i < s; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;

    if (dist[u][v] == 1) {
      std::cout << "-1\n";
    } else if (dist[v][u] == 1) {
      std::cout << "1\n";
    } else {
      std::cout << "0\n";
    }
  }
}