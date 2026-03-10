#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int n;
  std::cin >> n;
  std::vector<std::string> b(n);
  std::vector<P> doors, mirs;
  std::map<int, std::map<int, int>> rev;
  for (int i = 0; i < n; ++i) {
    std::cin >> b[i];
    for (int j = 0; j < n; ++j) {
      if (b[i][j] == '#') {
        doors.push_back({i, j});
      }
      if (b[i][j] == '!') {
        rev[i][j] = mirs.size();
        mirs.push_back({i, j});
      }
    }
  }

  int m = mirs.size();
  const int MAX = doors.size() + 2 * m;
  auto [sy, sx] = doors[0];
  auto [ty, tx] = doors[1];
  const int S = MAX - 2;
  const int T = S + 1;
  rev[sy][sx] = S;
  rev[ty][tx] = T;
  std::vector adj(MAX, std::vector<int>());
  for (int i = 0; i < m; ++i) {
    auto [y, x] = mirs[i];

    for (int dir = -1; dir < 2; dir += 2) {
      for (int step = 1;; ++step) {
        int ny = y + step * dir;
        if (ny < 0 || ny >= n || b[ny][x] == '*') {
          break;
        }
        if (b[ny][x] == '#' && ny == ty && x == tx) {
          adj[2 * i + 1].push_back(T);
          break;
        }
        if (b[ny][x] == '!') {
          adj[2 * i + 1].push_back(2 * rev[ny][x]);
        }
      }
    }

    for (int dir = -1; dir < 2; dir += 2) {
      for (int step = 1;; ++step) {
        int nx = x + step * dir;
        if (nx < 0 || nx >= n || b[y][nx] == '*') {
          break;
        }
        if (b[y][nx] == '#' && y == ty && nx == tx) {
          adj[2 * i].push_back(T);
          break;
        }
        if (b[y][nx] == '!') {
          adj[2 * i].push_back(2 * rev[y][nx] + 1);
        }
      }
    }
  }

  for (int dir = -1; dir < 2; dir += 2) {
    for (int step = 1;; ++step) {
      int ny = sy + step * dir;
      if (ny < 0 || ny >= n || b[ny][sx] == '*') {
        break;
      }
      if (b[ny][sx] == '#') {
        adj[S].push_back(T);
        break;
      }
      if (b[ny][sx] == '!') {
        adj[S].push_back(2 * rev[ny][sx]);
      }
    }
  }

  for (int dir = -1; dir < 2; dir += 2) {
    for (int step = 1;; ++step) {
      int nx = sx + step * dir;
      if (nx < 0 || nx >= n || b[sy][nx] == '*') {
        break;
      }
      if (b[sy][nx] == '#') {
        adj[S].push_back(T);
        break;
      }
      if (b[sy][nx] == '!') {
        adj[S].push_back(2 * rev[sy][nx] + 1);
      }
    }
  }

  std::queue<int> que;
  std::vector<int> dist(MAX, -1);
  dist[S] = 0;
  que.push(S);
  while (!que.empty()) {
    auto u = que.front();
    que.pop();
    for (auto v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        if (v == T) {
          std::println("{}", dist[u]);
        }
        que.push(v);
      }
    }
  }
}