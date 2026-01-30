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
  i64 a, b;
  std::cin >> a >> b;

  auto f = [&](i64 x) {
    i64 ret = 0;
    i64 w = 1;

    while (x >= w) {
      ret += x / w * (w - w / 2);
      w <<= 1;
    }

    return ret;
  };

  std::cout << f(b) - f(a - 1) << "\n";
}