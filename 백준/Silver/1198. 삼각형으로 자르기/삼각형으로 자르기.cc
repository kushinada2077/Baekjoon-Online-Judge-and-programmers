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
  std::vector<std::pair<double, double>> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first >> a[i].second;
  }

  std::vector<int> permutation(n, 1);
  for (int i = 0; i < 3; ++i) permutation[i] = 0;
  double ans = 0;

  do {
    std::vector<std::pair<double, double>> tmp;
    for (int i = 0; i < n; ++i) {
      if (permutation[i] == 0) {
        tmp.push_back({a[i].first, a[i].second});
      }
    }

    auto [x1, y1] = tmp[0];
    auto [x2, y2] = tmp[1];
    auto [x3, y3] = tmp[2];

    double res = std::abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) / 2;
    ans = std::max(ans, res);

  } while (std::next_permutation(permutation.begin(), permutation.end()));

  std::cout << std::fixed;
  std::cout << std::setprecision(10) << ans << "\n";
}