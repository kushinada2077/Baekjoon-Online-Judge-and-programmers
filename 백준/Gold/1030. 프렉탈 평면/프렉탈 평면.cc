#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define kushinada freopen(getenv("MY_PATH"), "r", stdin);
#else
#define kushinada
#endif

using i64 = long long;
using P = std::pair<int, int>;
using T = std::tuple<int, int, int>;

template <class T>
T power(T b, long long e) {
  T r(1);
  while (e) {
    if (e & 1) r *= b;
    b *= b;
    e /= 2;
  }
  return r;
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  kushinada;
  i64 s, n, k, r1, r2, c1, c2;
  std::cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

  auto dfs = [&](auto&& dfs, i64 s, i64 y, i64 x, i64 sy, i64 sx) -> i64 {
    if (s == 0) return 0;
    i64 ns = power<i64>(n, s - 1);
    i64 a = (n - k) * ns / 2;
    i64 b = power<i64>(n, s) - a;
    i64 ret = 0;
    if (sy + a <= y && y < sy + b && sx + a <= x && x < sx + b) return 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (sy + i * ns <= y && y < sy + (i + 1) * ns && sx + j * ns <= x && x < sx + (j + 1) * ns) {
          return ret = dfs(dfs, s - 1, y, x, sy + i * ns, sx + j * ns);
        }
      }
    }

    return ret;
  };

  for (int i = r1; i <= r2; ++i) {
    for (int j = c1; j <= c2; ++j) {
      std::print("{}", dfs(dfs, s, i, j, 0, 0));
    }
    std::println();
  }
}