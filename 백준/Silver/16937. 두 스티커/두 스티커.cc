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
  int h, w, n;
  std::cin >> h >> w >> n;
  std::vector<P> stickers(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> stickers[i].first >> stickers[i].second;
  }

  auto attatch = [&](int y1, int x1, int y2, int x2, int r) {
    if (r == 1) std::swap(y1, x1);
    if (r == 2) std::swap(y2, x2);
    if (r == 3) {
      std::swap(y1, x1);
      std::swap(y2, x2);
    }

    return (std::max(y1, y2) <= h && x1 + x2 <= w) || (y1 + y2 <= h && std::max(x1, x2) <= w);
  };

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      auto [y1, x1] = stickers[i];
      auto [y2, x2] = stickers[j];
      for (int r = 0; r < 4; ++r) {
        if (attatch(y1, x1, y2, x2, r)) {
          ans = std::max(ans, y1 * x1 + y2 * x2);
          break;
        }
      }
    }
  }

  std::cout << ans << "\n";
}