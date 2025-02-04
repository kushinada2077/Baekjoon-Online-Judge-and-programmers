#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  int lo = 0, hi = 1e9 + 1;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    lo = std::max(lo, a[i] - 1);
  }

  auto ok = [&](int mid) {
    int c = 0, t = 0;
    for (int i = 0; i < n; ++i) {
      if (t < a[i]) {
        t = mid - a[i];
        c++;
      } else {
        t -= a[i];
      }
    }

    return c <= m;
  };
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (ok(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  std::cout << hi << "\n";
}