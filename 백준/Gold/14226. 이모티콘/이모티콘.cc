#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using P_i64 = std::pair<i64, i64>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int s;
  std::cin >> s;

  std::queue<P> q;
  std::vector dist(2 * s, std::vector<int>(s + 1, -1));
  q.push({1, 0});
  dist[1][0] = 0;

  while (!q.empty()) {
    auto [u, clip] = q.front();
    q.pop();
    for (int dir = 0; dir < 3; ++dir) {
      if (dir == 0) {
        int new_clip = u;
        if (dist[u][new_clip] != -1) continue;
        q.push({u, new_clip});
        dist[u][new_clip] = dist[u][clip] + 1;
      } else if (dir == 1) {
        int v = u + clip;
        if (v >= 2 * s || dist[v][clip] != -1) continue;
        q.push({v, clip});
        dist[v][clip] = dist[u][clip] + 1;
      } else if (dir == 2) {
        int v = u - 1;
        if (v <= 0 || dist[v][clip] != -1) continue;
        q.push({v, clip});
        dist[v][clip] = dist[u][clip] + 1;
      }
    }
  }

  int ans = 0x3f3f3f3f;
  for (auto x : dist[s]) {
    if (x == -1) continue;
    ans = std::min(ans, x);
  }

  std::cout << ans << "\n";
}