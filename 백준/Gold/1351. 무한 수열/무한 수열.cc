#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, p, q;
  std::cin >> n >> p >> q;
  std::map<i64, i64> cache;

  cache[0] = 1;

  auto f = [&](auto&& f, i64 x) {
    if (x == 0) return 1LL;
    if (cache.contains(x)) return cache[x];
    i64 ret = f(f, x / p) + f(f, x / q);
    return cache[x] = ret;
  };

  std::cout << f(f, n) << "\n";
}