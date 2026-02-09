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
  int n, k;
  std::string a[2];
  std::cin >> n >> k >> a[0] >> a[1];
  std::vector dist(2, std::vector<int>(n, -1));

  std::queue<T> q;
  q.push({0, 0, 0});
  dist[0][0] = 0;
  std::vector dy = {0, 0, 1}, dx = {1, -1, k};
  while (!q.empty()) {
    auto [y, x, time] = q.front();
    q.pop();
    for (int dir = 0; dir < 3; ++dir) {
      int ny = (y + dy[dir]) % 2;
      int nx = x + dx[dir];
      if (nx >= n) {
        std::cout << "1\n";
        return 0;
      }
      if (nx < 0) continue;
      if (dist[ny][nx] != -1 || a[ny][nx] == '0') continue;
      if (nx <= time) continue;
      q.push({ny, nx, time + 1});
      dist[ny][nx] = dist[y][x] + 1;
    }
  }

  std::cout << "0\n";
}