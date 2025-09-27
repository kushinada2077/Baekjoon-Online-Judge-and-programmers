#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector tree_map(n, std::vector(n, std::vector<int>()));
  std::vector nut(n, std::vector<int>(n, 5));
  std::vector a(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }

  for (int i = 0; i < m; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    x--;
    y--;
    tree_map[x][y].push_back(z);
  }

  while (k--) {
    std::vector tmp(n, std::vector(n, std::vector<int>()));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        auto& tree_list = tree_map[i][j];
        std::ranges::sort(tree_list);
        for (auto it = tree_list.begin(); it != tree_list.end();) {
          if (nut[i][j] - (*it) >= 0) {
            nut[i][j] -= (*it);
            (*it)++;
            it++;
          } else {
            tmp[i][j].push_back(*it);
            it = tree_list.erase(it);
          }
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (auto& age : tmp[i][j]) {
          nut[i][j] += age / 2;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int cnt = 0;
        for (auto& age : tree_map[i][j]) {
          if (age % 5 == 0) cnt++;
        }

        for (int k = 0; k < cnt; ++k) {
          for (int dir = 0; dir < 8; ++dir) {
            int ni = i + "00012221"[dir] - '1';
            int nj = j + "01222100"[dir] - '1';
            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
            tree_map[ni][nj].push_back(1);
          }
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        nut[i][j] += a[i][j];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans += (int)tree_map[i][j].size();
    }
  }

  std::cout << ans << "\n";
}