#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

struct SCC {
  int n;
  int cur, cnt;
  std::vector<std::vector<int>> adj;
  std::vector<int> dfn, low, bel;
  std::vector<int> stk;

  SCC(int n) : n(n), cur(0), cnt(0), adj(n), dfn(n, -1), low(n), bel(n, -1) {}

  void addEdge(int u, int v) { adj[u].push_back(v); }

  void dfs(int u) {
    dfn[u] = low[u] = cur++;
    stk.push_back(u);

    for (auto v : adj[u]) {
      if (dfn[v] == -1) {
        dfs(v);
        low[u] = std::min(low[u], low[v]);
      } else if (bel[v] == -1) {
        low[u] = std::min(low[u], dfn[v]);
      }
    }

    if (dfn[u] == low[u]) {
      int v;
      do {
        v = stk.back();
        stk.pop_back();
        bel[v] = cnt;
      } while (v != u);
      cnt++;
    }
  }

  std::vector<int> work() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) dfs(i);
    }
    return bel;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  int r, s;
  std::cin >> r >> s;
  std::vector<std::string> board(r);
  std::map<P, int> towers;
  for (int i = 0; i < r; ++i) {
    std::cin >> board[i];
    for (int j = 0; j < s; ++j) {
      if (board[i][j] == 'T') {
        towers[{i, j}] = (int)towers.size();
      }
    }
  }

  std::vector dy = {-1, 1, 0, 0}, dx = {0, 0, -1, 1};
  SCC scc(4 * (int)towers.size());

  auto look = [&](int y, int x, int dir) -> int {
    for (int step = 1;; ++step) {
      int ny = y + step * dy[dir];
      int nx = x + step * dx[dir];
      if (ny < 0 || ny >= r || nx < 0 || nx >= s) break;
      if (board[ny][nx] == '#') break;
      if (board[ny][nx] == 'T') return towers[{ny, nx}];
    }

    return -1;
  };

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      if (board[i][j] == 'n') {
        std::vector<int> arounds(4);
        std::vector<bool> exists(4);
        for (int dir = 0; dir < 4; ++dir) {
          arounds[dir] = look(i, j, dir);
          if (arounds[dir] != -1) exists[dir] = true;
        }

        int sum = 0;
        for (int i = 0; i < 4; ++i) sum += exists[i];

        if (sum == 1) {
          int dir = 0;
          for (int i = 0; i < 4; ++i) {
            if (exists[i] == 1) dir = i;
          }

          int u = 4 * arounds[dir] + dir;
          scc.addEdge(u ^ 1, u);

        } else if (sum == 2) {
          std::vector<int> dirs;
          for (int dir = 0; dir < 4; ++dir) {
            if (exists[dir]) dirs.push_back(dir);
          }

          int u = 4 * arounds[dirs[0]] + dirs[0];
          int v = 4 * arounds[dirs[1]] + dirs[1];
          scc.addEdge(u ^ 1, v);
          scc.addEdge(v ^ 1, u);

        } else if (sum == 3) {
          int dir = 0;
          for (int i = 0; i < 4; ++i) {
            if (exists[i] == 0) dir = i;
          }

          dir ^= 1;
          int u = 4 * arounds[dir] + dir;
          scc.addEdge(u ^ 1, u);
        }
      }
    }
  }

  for (auto [coor, n] : towers) {
    auto [y, x] = coor;
    for (int dir = 0; dir < 4; ++dir) {
      for (int step = 1;; ++step) {
        int ny = y + step * dy[dir];
        int nx = x + step * dx[dir];
        if (ny < 0 || ny >= r || nx < 0 || nx >= s) break;
        if (board[ny][nx] == '#') break;
        if (board[ny][nx] == 'T') {
          int u = 4 * n + dir;
          scc.addEdge(u ^ 1, u);
          break;
        }
      }
    }
  }

  auto bel = scc.work();
  int k = (int)towers.size();
  std::vector<P> towers_dir(k);

  for (int i = 0; i < k; ++i) {
    int down, right;

    if (bel[4 * i] == -1) down = 0;
    else if (bel[4 * i + 1] == -1) down = 1;
    else if (bel[4 * i] > bel[4 * i + 1]) down = 0;
    else down = 1;

    if (bel[4 * i + 2] == -1) right = 0;
    else if (bel[4 * i + 3] == -1) right = 1;
    else if (bel[4 * i + 3] != -1 && bel[4 * i + 2] > bel[4 * i + 3]) right = 0;
    else right = 1;

    towers_dir[i] = {down, right};
  }

  int cnt = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      if (board[i][j] == 'T') {
        auto [down, right] = towers_dir[cnt++];
        if (down && right) std::cout << "2";
        else if (down && !right) std::cout << "1";
        else if (!down && right) std::cout << "3";
        else std::cout << "4";
      } else {
        std::cout << board[i][j];
      }
    }
    std::cout << "\n";
  }
}