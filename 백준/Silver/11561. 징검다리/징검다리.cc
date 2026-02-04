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
  int t;
  std::cin >> t;
  while (t--) {
    i64 n;
    std::cin >> n;

    i64 lo = 0, hi = 1e9 + 1;

    while (lo + 1 < hi) {
      i64 mid = (lo + hi) / 2;
      if ((mid + 1) * mid <= 2 * n) lo = mid;
      else hi = mid;
    }

    std::cout << lo << "\n";
  }
}