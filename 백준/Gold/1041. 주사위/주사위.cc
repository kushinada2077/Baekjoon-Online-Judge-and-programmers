#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using TP = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  const int INF = 0x3f3f3f3f;
  i64 n;
  std::cin >> n;

  std::vector<i64> a(6);
  i64 min_a = INF, min_b = INF, min_c = INF;
  for (int i = 0; i < 6; ++i) {
    std::cin >> a[i];
    min_a = std::min(min_a, a[i]);
  }

  if (n == 1) {
    i64 sum = 0;
    for (int i = 0; i < 6; ++i) {
      sum += a[i];
    }
    std::println("{}", sum - *std::ranges::max_element(a));
    return 0;
  }

  std::vector<std::vector<int>> team = {{0, 5}, {1, 4}, {2, 3}};
  for (int i = 0; i < 3; ++i) {
    for (auto u : team[i]) {
      for (int j = i + 1; j < 3; ++j) {
        for (auto v : team[j]) {
          min_b = std::min(min_b, a[u] + a[v]);
        }
      }
    }
  }

  for (auto u : team[0]) {
    for (auto v : team[1]) {
      for (auto w : team[2]) {
        min_c = std::min(min_c, a[u] + a[v] + a[w]);
      }
    }
  }

  i64 ans = ((n - 1) * 4 + (n - 2) * 4) * min_b + min_c * 4 + ((n - 1) * (n - 2) * 4 + (n - 2) * (n - 2)) * min_a;
  std::println("{}", ans);
}