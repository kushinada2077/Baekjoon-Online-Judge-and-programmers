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
  int t = 4;
  while (t--) {
    std::vector res(6, std::vector<int>(3));
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 3; ++j) {
        std::cin >> res[i][j];
      }
    }

    bool ans = false;
    auto dfs = [&](auto&& dfs, int i, int j) {
      if (ans) return;
      if (i == 5) {
        bool ok = [&] {
          for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
              if (res[i][j]) return false;
            }
          }

          return true;
        }();

        if (ok) ans = true;
        return;
      }

      if (res[i][0] > 0 && res[j][2] > 0) {
        res[i][0]--;
        res[j][2]--;
        if (j == 5) dfs(dfs, i + 1, i + 2);
        else dfs(dfs, i, j + 1);
        res[i][0]++;
        res[j][2]++;
      }

      if (res[i][1] > 0 && res[j][1] > 0) {
        res[i][1]--;
        res[j][1]--;
        if (j == 5) dfs(dfs, i + 1, i + 2);
        else dfs(dfs, i, j + 1);
        res[i][1]++;
        res[j][1]++;
      }

      if (res[i][2] > 0 && res[j][0] > 0) {
        res[i][2]--;
        res[j][0]--;
        if (j == 5) dfs(dfs, i + 1, i + 2);
        else dfs(dfs, i, j + 1);
        res[i][2]++;
        res[j][0]++;
      }
    };

    dfs(dfs, 0, 1);
    if (ans) std::cout << "1 ";
    else std::cout << "0 ";
  }
}