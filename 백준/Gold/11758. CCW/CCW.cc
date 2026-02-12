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
  int x1, y1, x2, y2, x3, y3;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  auto cross = [&](int x1, int y1, int x2, int y2) { return x1 * y2 - x2 * y1; };

  int c = cross(x2 - x1, y2 - y1, x3 - x2, y3 - y2);
  if (c > 0) std::cout << "1\n";
  else if (c == 0) std::cout << "0\n";
  else std::cout << "-1\n";
}