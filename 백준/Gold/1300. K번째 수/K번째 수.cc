#include <bits/stdc++.h>
using i64 = long long;

bool ok(i64 mid, i64 n, i64 k) {
  i64 down = 0;
  for (int i = 1; i <= n; ++i) {
    down += std::min(n, mid / i);
  }

  return down >= k;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, k;
  std::cin >> n >> k;
  i64 lo = 0, hi = n * n + 1;
  while (lo + 1 < hi) {
    i64 mid = (lo + hi) / 2;
    if (ok(mid, n, k)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  std::cout << hi << "\n";
}