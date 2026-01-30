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
  std::vector<i64> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::sort(a.begin(), a.end());
  i64 ans = 0;

  for (int i = 0; i < n; ++i) {
    auto it = std::upper_bound(a.begin() + i + 1, a.end(), a[i] * 10 / 9);
    if (it == a.end() && a.back() > a[i] * 10 / 9) continue;
    ans += it - a.begin() - i - 1;
  }

  std::cout << ans << "\n";
}