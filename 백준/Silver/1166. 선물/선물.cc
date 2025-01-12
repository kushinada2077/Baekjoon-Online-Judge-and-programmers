#include <bits/stdc++.h>
using i64 = long long;

i64 n, l, w, h;
bool ok(double mid) {
  if (mid > std::max({l, w, h})) return false;
  return i64(l / mid) * i64(w / mid) * i64(h / mid) >= n;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n >> l >> w >> h;

  double lo = 0, hi = 1e9;
  int c = 100;
  while (c-- && lo < hi) {
    double mid = (lo + hi) / 2;
    if (ok(mid)) lo = mid;
    else hi = mid;
  }

  std::cout << std::fixed << std::setprecision(10) << lo << "\n";
}