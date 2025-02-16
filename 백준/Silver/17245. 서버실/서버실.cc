#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  i64 tot = 0;
  std::cin >> n;
  std::vector a(n, std::vector<i64>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
      tot += a[i][j];
    }
  }

  auto ok = [&](i64 x) {
    i64 cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cnt += std::min(a[i][j], x);
      }
    }

    return 2 * cnt >= tot;
  };

  i64 lo, hi;
  for (lo = -1, hi = 1e10; lo + 1 < hi;) {
    i64 mid = (lo + hi) / 2;
    if (ok(mid)) hi = mid;
    else lo = mid;
  }

  std::cout << hi << "\n";
}