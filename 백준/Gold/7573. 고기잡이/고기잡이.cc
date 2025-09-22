#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, l, m;
  std::cin >> n >> l >> m;
  std::vector fish(m, std::vector<int>(2));
  for (int i = 0; i < m; ++i) {
    std::cin >> fish[i][0] >> fish[i][1];
  }

  int ans = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      auto solve = [&](int type) {
        int s = std::min(fish[i][type], fish[j][type]), e = std::max(fish[i][type], fish[j][type]);
        if (e == s || e - s > (l - 2) / 2) return 0;

        std::vector<int> a_set;
        for (auto elem : fish) {
          if (s <= elem[type] && elem[type] <= e) {
            a_set.push_back(elem[(type + 1) % 2]);
          }
        }

        std::ranges::sort(a_set);
        int ret = 0;
        int u = 0;
        for (int k = 0; k < (int)a_set.size(); ++k) {
          while (u < (int)a_set.size() && a_set[u] - a_set[k] <= l / 2 - (e - s)) {
            u++;
          }
          ret = std::max(ret, u - k);
        }

        return ret;
      };

      ans = std::max({ans, solve(0), solve(1)});
    }
  }

  std::cout << ans << "\n";
}