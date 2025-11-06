#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using P_i64 = std::pair<i64, i64>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<P_i64> a(n);
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first >> a[i].second;
    sum += a[i].second;
  }
  std::ranges::sort(a);

  i64 tot = 0;
  for (int i = 0; i < n; ++i) {
    auto d = a[i].second;
    tot += d;
    if (tot * 2 >= sum) {
      std::cout << a[i].first << "\n";
      return 0;
    }
  }
}